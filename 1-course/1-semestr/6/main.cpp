//Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100.
// Если все диагональные элементы матрицы являются наибольшими элементами своих строк,
// заменить элементы матрицы, содержащие цифру 0, на произведение диагональных элементов.
#include <iostream>
#include "fun.hpp"
int main()
{
    int n;
    int matrix[100][100];
    number6::Read(matrix, n);

    int k;
    bool flag = number6::Condition(matrix, n, k);

    if (flag)
    {
        number6::dff(matrix, n, k);
    }
    number6::isExit(n,matrix);
    return 0;
}