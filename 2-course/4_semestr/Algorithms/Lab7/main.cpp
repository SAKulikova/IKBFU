//7.	Реализовать алгоритм Прима нахождения минимального покрывающего дерева.
//Будем искать вес минимального остовного дерева. Для нахождения ближайшей вершины
// воспользуемся очередью с приоритетом (аналогично алгоритму Дейкстры),
// в которой будем хранить пары (расстояние от остова до вершины, номер вершины).
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> graph[1000];
bool used[1000];      //включили ли мы соответствующую вершину в остов

int main() {
    std::string filename = "matrix.txt";
    std::ifstream file(filename);
    int n;
    file >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matrix[i][j];
            if (matrix[i][j] != 0)
            {
                // Добавляем ребра в граф
                graph[i].push_back({j, matrix[i][j]});
                graph[j].push_back({i, matrix[i][j]});
            }
        }
    }

    file.close();

    int mst_weight = 0;     //Текущий вес остова.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});     //Начнём с вершины 0.

    while (!q.empty())
    {
        pair<int, int> c = q.top();//извлекается вершина с наименьшим расстоянием (c) и удаляется из очереди.
        q.pop();

        int dst = c.first, v = c.second;

        if (used[v]) {      //вершина уже добавлена в остов
            continue;
        }

        used[v] = true;
        mst_weight += dst;

        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            if (!used[u]) { //проверяем, не была ли уже использована смежная вершина u
                q.push({len_vu, u});    // учитываем только длину ребра.
            }
        }
    }

    cout << "Минимальный вес покрывающего дерева: " << mst_weight << endl;
}

