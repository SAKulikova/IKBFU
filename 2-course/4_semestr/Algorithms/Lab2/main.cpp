//2.  Найти в заданном графе кратчайшие пути из заданной вершины до всех остальных вершин с помощью поиска в ширину
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> bfs(const vector<vector<int>>& graph, int start)
{
    unsigned long n = graph.size(); //кол-во вершин в графе
    std::vector<int> dist(n, INF);//устанавливаем все расстояния равные какому-то большому числу
    dist[start] = 0;//расстояние до начальной вершины как 0
    queue<int> q;//очередь для обхода графа
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();  // Извлекаем текущую вершину из очереди
        q.pop();
        for (int neighbor = 0; neighbor < n; neighbor++)// Проходим по всем смежным вершинам
         {
            if (graph[vertex][neighbor] == 1 && dist[neighbor] == INF)// Если соседняя вершина существует и мы еще не посетили ее
            {
                dist[neighbor] = dist[vertex] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main() {
    int start;
    ifstream input_file("graph.txt");
    ofstream output_file("output.txt");
    int n;
    input_file >> n;

    vector<vector<int>> graph(n, vector<int>(n));// Создаем двумерный вектор для представления графа
    for (int i = 0; i < n; ++i) {//Считываем матрицу смежности
        for (int j = 0; j < n; ++j) {
            input_file >> graph[i][j];
        }
    }

    vector<int> shortest_paths = bfs(graph, start);

    for (int i = 0; i < n; i++) {
        output_file << "Крайтчайший путь от вершины " << start +1 << " до вершины " << i + 1<< " равен " << shortest_paths[i] << endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}