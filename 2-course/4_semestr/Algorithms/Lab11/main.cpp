////алгоритм поиска по образцу с помощью конечного автомата
//AABA

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildTransitionFunction(const string& pattern) {//строим таблицу переходов для конечного автомата по образцу pattern.

    int m = pattern.size();//длина образца
    vector<int> tf(m + 1, 0);
    tf[0] = -1;
    int i = 0, j = -1;
//Затем происходит заполнение вектора tf в соответствии с алгоритмом построения таблицы переходов.
    while (i < m)
    {
        while (j >= 0 && pattern[i] != pattern[j])
            j = tf[j];
        i++;
        j++;
        tf[i] = j;
    }

    return tf;
}

//ищет все вхождения образца pattern в строке text с помощью конечного автомата используя таблицу переходов.
void searchPattern(const string& text, const string& pattern) {
    vector<int> tf = buildTransitionFunction(pattern);
    int n = text.size();
    int m = pattern.size();
//Затем осуществляется проход по строке text, где для каждого символа проверяется совпадение с образцом.
    int i = 0, j = 0;
    while (i < n)
    {
        while (j >= 0 && text[i] != pattern[j])
            j = tf[j];
        i++;
        j++;
        if (j == m)
        {
            cout << "Строка найдена на индексе " << i - j << endl;
            j = tf[j];
        }
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "Не удалось открыть файл" << endl;
        return 1;
    }

    string text;
    if (getline(file, text))
    {
        string pattern;
        cout << "Введите строку поиска: ";
        cin >> pattern;

        searchPattern(text, pattern);
    }
    else {
        cout << "Файл пустой" << endl;
    }

    file.close();

    return 0;
}
