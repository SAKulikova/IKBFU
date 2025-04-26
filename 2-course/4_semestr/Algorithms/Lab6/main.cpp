//6.	Реализовать алгоритм Крускала нахождения минимального покрывающего дерева.
//Алгоритм заключается в сортировке всех рёбер в порядке возрастания длины,
// и поочерёдному добавлению их в минимальный остов, если они соединяют различные компоненты связности.
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Edge
{
    int src, dest, weight;
};
// Сравниваем ребра по возрастанию веса
bool compare(const Edge& a, const Edge& b)
{
    return a.weight < b.weight;
}

// Находим представителя множества для текущей вершины графа
int find(std::vector<int>& parent, int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}
int main()
{

    std::ifstream input("matrix.txt");

    int V; // Количество вершин в графе
    input >> V;

    //  Создаем матрицу смежности для хранения графа
    std::vector<std::vector<int>> graph(V, std::vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            input >> graph[i][j];
        }
    }
    input.close();

    // Создаем вектор ребер графа и заполняем его
    std::vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                Edge e = {i, j, graph[i][j]};
                edges.push_back(e);
            }
        }
    }

    // Сортируем ребра по возрастанию веса
    sort(edges.begin(), edges.end(), compare);

    std::vector<int> parent(V, -1); // Вектор для хранения представителей множеств

    std::vector<Edge> result; // Результат - минимальное покрывающее дерево

    // Обход все ребра и соедине их, если они принадлежат различным множествам
    for (Edge e : edges)
    {
        int x = find(parent, e.src);
        int y = find(parent, e.dest);
        if (x != y) {
            result.push_back(e);
            parent[x] = y;
        }
    }


    std::cout << "Результат \nРебро, вес ребра: " << std::endl;
    int totalWeight = 0;
    for (Edge e : result)
    {
        std::cout << e.src << " --- " << e.dest << ": " << e.weight << std::endl;
        totalWeight += e.weight;
    }
    std::cout << "Суммарный вес: " << totalWeight << std::endl;


    return 0;
}
