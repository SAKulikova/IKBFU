//5.	Найти в заданном орграфе количество и состав сильно связных компонент с помощью поиска в глубину.
#include <iostream>
#include <fstream>
#include <vector>

//Функция для обхода графа в глубину. Посещаем вершину v, отмечает ее как посещенную, добавляет вершину в порядок обхода
// и рекурсивно вызывает себя для всех смежных вершин.
void dfs(int v, std::vector<bool>& visited, std::vector<int>& order, std::vector<std::vector<int>>& matrix)
{
    visited[v] = true;
    for (int i = 0; i < matrix.size(); i++)
        if (matrix[v][i] && !visited[i])
            dfs(i, visited, order, matrix);
    order.push_back(v);
}

//Функция для обхода графа с обращенными направлениями ребер (инвертированный)
void dfsTranspose(int v, std::vector<bool>& visited, std::vector<int>& component, std::vector<std::vector<int>>& transposeMatrix)
{
    visited[v] = true;
    component.push_back(v);
    for (int i = 0; i < transposeMatrix.size(); i++)
    {
        if (transposeMatrix[v][i] && !visited[i])
        {
            dfsTranspose(i, visited, component, transposeMatrix);
        }
    }
}

std::vector<std::vector<int>> findStronglyConnectedComponents(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    std::vector<bool> visited(n); // для отслеживания посещенных вершин
    std::vector<int> order; // для сохранения порядка обхода вершин

    //обход для формирования порядка вершин
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, order, matrix);
        }
    }

    std::vector<std::vector<int>> transposeMatrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    visited.assign(n, false);
    std::vector<std::vector<int>> result;

//    нахождения компонент
    for (int i = n - 1; i >= 0; i--)
    {
        int v = order[i];
        if (!visited[v])
        {
            std::vector<int> component;
            dfsTranspose(v, visited, component, transposeMatrix);
            result.push_back(component);
        }
    }
    return result;
}

int main()
{
    std::ifstream inputFile("graph.txt");
    std::ofstream outputFile("output.txt");

    int n;
    inputFile >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    // считываем матрицу смежности из файла
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> graph[i][j];
        }
    }

    std::vector<std::vector<int>> result = findStronglyConnectedComponents(graph);

    outputFile << "Количество компонент связности:  " << result.size() << std::endl;
    outputFile << "Состав компонент связности: " << std::endl;
    for (int i = 0; i < result.size(); i++)
    {
        outputFile << "Компонента " << i + 1 << ": ";
        for (int j = 0; j < result[i].size(); j++)
        {
            outputFile << result[i][j] << " ";
        }
        outputFile << std::endl;
    }
    return 0;
}
