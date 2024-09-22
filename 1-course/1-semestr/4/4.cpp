//Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
// Если в последовательности нет чисел, все цифры которых одинаковы, упорядочить последовательность по невозрастанию.
#include <iostream>
int main() {
    int n;
    int a=0;
    std::cin >> n;
    int mas[10000];
    int x;
    int y;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        std::cin >> y;
        mas[i] = y;
        x = y;
        for (int p=0; p<x; p++)
        {
            a=y%10;
            y=x/10;
            while (x>0)
            {
                if ((x > 9) & (x % 10 == x / 10 % 10)) {
                    flag = false;
                }
                //std::cout << y << " " << std::endl;
                else
                {
                    flag=true;
                }
                x = x / 10;
            }
        }

    }
    if (flag) {
        for (int d = 0; d < n - 1; d++)
            for (int j = d + 1; j < n; j++) {

                // Сложный ключ
                if ((mas[d] < mas[j])) {
                    // обмен
                    std::swap(mas[d], mas[j]);
                }
            }
    }
    for (int e = 0; e < n; e++)
        std::cout << mas[e]  << std::endl;
}

