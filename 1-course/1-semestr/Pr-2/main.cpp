#include <iostream>
int main()
{
    std::string A;
    std::string B;
    std::cin >> A >> B;
    const int N = 1000;
    int mas1[N] = {0};
    int mas2[N] ={0};
    for (int i = 0; i < size(A); i++)
        mas1[i] = (int)A[i] - 48;
    for (int i = 0; i < size(B); i++)
        mas2[i] = (int)B[i] - 48;
    int mas3[N + 1] = {0};
    for (int i = 0; i < size(A) / 2; i++)
        std::swap(mas1[i], mas1[size(A) - i -1]);
    for (int i = 0; i < size(B) / 2; i++)
        std::swap(mas2[i], mas2[size(B) - i - 1]);

    int t;
    if (size(A) > size(B))
        t = size(A);
    else
        t = size(B);
    int ost = 0;
    for (int i = 0; i < t; i++)
    {
        mas3[i] = (mas1[i] + mas2[i]) % 10 + ost;
        ost = (mas1[i] + mas2[i]) / 10;
    }

    std::cout << std::endl;
    if (ost == 1) {
        mas3[t] = 1;
        t++;
    }

    for (int i = 0; i < t/2; i++)
    {
        std::swap(mas3[i], mas3[t - i - 1]);

    }
    if (mas3[0] == 0)
    {
        t--;
        for (int i = 0; i < t; i++)
            mas3[i] = mas3[i + 1];
    }
    std::cout << "Summa:";
    if (A=="0" & B=="0"){
        std::cout<<0;
    }
    else{
        for (int i = 0; i < t; i++)
            std::cout << mas3[i];
    }
    std::cout<<std::endl;

    int dl = size(A) + size(B) + 1;
    int d[100000]={0};

    for (int i = 0; i < size(A); i++)
        for (int j = 0; j < size(B); j++)
            d[i + j] += mas1[i] * mas2[j];

    for (int i = 0; i < dl; i++) {
        d[i + 1] += d[i] / 10;
        d[i] %= 10;
    }
    while (d[dl - 1] == 0)
    {
        if ((dl == 1)  & (d[0] == 0))
        {
            break;
        }
        dl--;
    }
    for (int i = 0; i < dl / 2; i++)
        std::swap(d[i], d[dl - i - 1]);
    std::cout << "Multiplication:";

    for (int i = 0; i < dl; i++)
        std::cout << d[i];
    std::cout << std::endl;
}