//Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
// Найти строку с наибольшей суммой элементов и увеличить все элементы этой строки на 1.
#include <iostream>
int main() {
    int n;
    int m;
    //int matrixx[n][m];
    std::cin >> n;
    std::cin >> m;
    int matrix[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
    int max=0;
    int ind=0;
    for (int i=0; i<n; i++){
        int sum=0;
        for (int j=0; j<m; j++){
            sum+=matrix[i][j];
        }
        if (sum>max){
            ind=i;
            max=sum;
        }
    }
    for (int j=0; j<m; j++){
        matrix[ind][j]+=1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}