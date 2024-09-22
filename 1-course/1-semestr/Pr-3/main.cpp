//В текстовом файле input.txt записан английский текст.
// Найти в тексте слова, содержащие не менее четырех различных гласных букв, записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
// Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
int main() {
    std::string glass = "AEIOUYaeiouy";
    std::ifstream in("input.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);
    std::string word;
    std::vector<char> glassInWord;
    while (in >> word) {
        glassInWord.clear();
        for (int i = 0; i < word.length(); i++) {
            for (int s = 0; s < glass.size(); s++)
                if (word[i] == glass[s]) {
                    bool flag = true;
                    for (char n: glassInWord)
                        if (n == word[i])
                            flag = false;
                    if (flag == true)
                        glassInWord.push_back(word[i]);
                }
        }
        if (glassInWord.size() >= 4) {
            for (int j = 0; j < word.length(); j++)
                for (int w = 0; w < glass.size(); w++)
                    if (word[j] == glass[w] && (int) word[j] > 90)
                        word[j] = (char) ((int) word[j] - 32);
        }
        std::string param = "";
        if (ispunct(word[size(word) - 1]) != 0) {
            param = word[size(word) - 1];
            word.erase(word.cend() - 1);
        }
        out << word;
        if (glassInWord.size() >= 4) {
            out<< '(';
            for (char n: glassInWord) {
                out<< n;
            }
            out<< ")";
        }
        out<<param<< ' ';
    }
}