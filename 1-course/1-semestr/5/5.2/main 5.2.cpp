//Дан файл, содержащий текст, размер текста не превышает 10 К байт. соня лох
// Найти в тексте N (N ≤ 100) самых длинных слов, содержащих заданную букву и не содержащих другую заданную букву.
// Записать найденные слова в текстовый файл в порядке не возрастания длины. Все найденные слова должны быть разными. Число N вводить из файла.
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
int main() {
    int n;
    char k;
    char h;
    std::cout << "Введите букву, которая НЕ должна содержаться в слове" << std::endl;
    std::cin >> k;
    std::cout << "Введите букву, которая должна содержаться в слове" << std::endl;
    std::cin >> h;
    std::ifstream in("text.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);
    in >> n;
    std::string words[10000] = {};
    int t = 0;
    while (!in.eof()) {
        std::string word;
        in >> word;
        if (ispunct(word[0]) != 0) {
            word.erase(word.cbegin());
        }
        if (ispunct(word[size(word) - 1]) != 0) {
            word.erase(word.cend() - 1);
        }
        bool isConsistFirstLetter = false;
        bool isConsistSecondLetter = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == k)
                isConsistFirstLetter = true;
            if (word[i] == h)
                isConsistSecondLetter = true;
        }
        std::cout << isConsistFirstLetter << " " << isConsistSecondLetter << std::endl;
        if (!isConsistFirstLetter && isConsistSecondLetter) {
            bool replay = false;
            for (int f = 0; f < t; f++) {
                std::cout << words[f] << " " << word << std::endl;
                if (words[f] == word) {
                    std::cout << "111" << std::endl;
                    replay = true;
                    break;
                }
            }
            if (!replay) {
                words[t] = word;
                t++;
            }
        }
    }
    for (int g = 0; g < t; g++)
        for (int a = 0; a < t; a++)
        {
            if (words[g].length() > words[a].length())
            {
                std::swap(words[g], words[a]);
            }
        }
    for (int s=0; s<n; s++)
    {
        out<<words[s]<<std::endl;
    }
    return 0;
}