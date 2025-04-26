//9.	Реализовать алгоритм Беллмана-Форда поиска кратчайших путей из одной вершины
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

struct Edge
{
    int from;
    int to;
    int weight;
};

void BellmanFord(int n, int start, std::vector<Edge>& edges, std::vector<int>& distances)
{
    distances.assign(n, INF);
    distances[start] = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < edges.size(); ++j)
        {
            int u = edges[j].from;
            int v = edges[j].to;
            int weight = edges[j].weight;
            if (distances[u] < INF)
            {
                distances[v] = std::min(distances[v], distances[u] + weight);
            }
        }
    }
}

int main()
{
    std::ifstream fin("matrix.txt");
    int n;
    fin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> graph[i][j];
        }
    }
    fin.close();

    std::vector<Edge> edges; // создаем вектор ребер
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (graph[i][j] != 0 && graph[i][j] != INF)
            {
                edges.push_back({ i, j, graph[i][j] }); // добавляем ребро в вектор
            }
        }
    }

    std::vector<int> distances(n);
    int start = 0;

   BellmanFord(n, start, edges, distances);

    std::ofstream fout("output.txt");
    for (int i = 0; i < n; ++i)
    {
        fout << "Кратчайший путь из вершины " << start << " до вершины " << i << " : " << distances[i] << std::endl;
    }
    fout.close();

    return 0;
}
