//10.	Реализовать алгоритм нахождения эйлерова цикла в неориентированном графе, заданном матрицей смежности.
#include <iostream>
#include <fstream>
#include <vector>

const int MAXN = 100;
std::vector<int> path;
int n;
int a[MAXN][MAXN];

// функция поиска эйлерова цикла
void find_euler_cycle(int v)
{
    for (int u = 0; u < n; ++u)
    {
        if (a[v][u] == 1)
        {
            a[v][u] = 0;
            a[u][v] = 0;
            find_euler_cycle(u); // продолжаем обход из этой вершины
        }
    }
    path.push_back(v + 1); // добавляем вершину в путь
}


int main()
{
    std::ifstream fin("graph.txt");
    fin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> a[i][j];
    fin.close();

    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        int degree = 0;
        for (int j = 0; j < n; ++j)
        {
            degree += a[i][j];
        }
        if (degree % 2 == 1)   //Связный граф эйлеров тогда и только тогда, когда в нем степени всех вершин четны.
        {
            std::cout << "No" << std::endl;
            return 0;
        }
        if (degree > 0)
        {
            start = i;
        }
    }

    find_euler_cycle(start);

    std::ofstream fout("output.txt");

    if (path.size() == 1)// случай, когда граф состоит только из одной вершины
    {
        fout << path[0];
    }
    else// случай, когда граф содержит несколько вершин
    {
        for (int i = path.size() - 1; i >= 0; --i)
        {
            fout << path[i] << " ";
        }
    }
    fout.close();

    return 0;
}
