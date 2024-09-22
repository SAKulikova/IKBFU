#include "fun.hpp"
#include <iostream>
namespace number6
{
    void Read(int matrix[100][100], int& n)
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                std::cin >> matrix[i][j];
    }
    void isExit(int n, int matrix[100][100])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool Condition(int matrix[100][100], int n, int& k)
    {
        int max = 0;
        k = 1;
        bool flag=false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] > matrix[i][j + 1])
                {
                    max = matrix[i][j];
                    if (matrix[i][i] == max)
                    {
                        k *= max;
                        flag = true;
                    }
                    max = 0;
                }
            }
        }
        return flag;
    }
    void dff(int matrix[100][100], int n, int& k){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    matrix[i][j] = k;
            }
        }
    }
}