//Дана строка длиной не более 100 символов. Отсортировать слова в ней в алфавитном порядке.
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <set>
#include <algorithm>
int main() {
    char str [100][100];
    std::ifstream in("input.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);
    std::string words[100] = {};
    int t = 0;
    while (!in.eof()) {
        std::string word;
        in >> word;
        words[t] = word;
        t++;
    }
    for (int j=0; j<t; j++){
        for(int k=0; k<t-1; k++){
            if (words[j]<words[k]){
                std::swap(words[k], words[j]);
            }
        }
    }
    for (int i=0; i<t;i++)
    {
        std::cout<<words[i]<<std::endl;
        out << words[i] << std::endl;
    }
}