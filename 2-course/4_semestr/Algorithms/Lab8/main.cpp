//8.	Реализовать алгоритм Дейкстры поиска кратчайших путей из одной вершины,
// используя в качестве приоритетной очереди обычный массив
#include <iostream>
#include <fstream>
#include <vector>

const int INF = 1e9;
void dijkstra_algorithm(int start, std::vector<std::vector<int>>& graph, std::vector<int>& dist)
{
    std::vector<bool> visited(dist.size(), false); // массив для отслеживания посещения вершин
    dist[start] = 0;

    for (int i = 0; i < dist.size() - 1; i++)// проходим по всем вершинам, кроме стартовой
    {
        int minDist = INF;
        int minIndex = -1;

        for (int j = 0; j < dist.size(); j++)
        { // ищем вершину с наименьшим расстоянием
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                minIndex = j;
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = true;

        for (int j = 0; j < dist.size(); j++)// обновляем расстояния до смежных вершин
        {
            int weight = graph[minIndex][j];
            if (weight != 0 && dist[minIndex] != INF && dist[minIndex] + weight < dist[j])
            {
                dist[j] = dist[minIndex] + weight;
            }
        }
    }
}
int main()
{
    std::string filename = "matrix.txt";
    std::ifstream file(filename);
    int n;
    file >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> graph[i][j];
        }
    }

    file.close();

    int startVertex = 1;

    std::vector<int> distances(n, INF); // массив расстояний от стартовой вершины до каждой другой вершины

    dijkstra_algorithm(startVertex - 1, graph, distances);

    std::ofstream out("output.txt");
    for (int i = 0; i < distances.size(); i++)
    {
        out << "Кратчайший путь из вершины " << startVertex << " до вершины " << i + 1 << ": ";
        if (distances[i] == INF)
        {
            out << "no path" << std::endl;
        }
        else
        {
            out << distances[i] << std::endl;
        }
    }

    out.close();

    return 0;
}
