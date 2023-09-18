#include "struct.h"
#include "algorithm.h"

// Алгоритм Дейкстры:

// Функция для поиска длины кратчайшего пути от вершины 0 до вершины 9 с помощью алгоритма Дейкстры
int dijkstra(vector<Edge> edges, int numVertices) {
    // Создаем вектор расстояний от вершины 0 до каждой другой вершины графа
    vector<int> distance(numVertices, INT_MAX);
    distance[0] = 0;

    // Создаем приоритетную очередь для хранения пар (расстояние, вершина)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Проходим по всем ребрам, исходящим из текущей вершины
        for (auto edge : edges) {
            if (edge.source == u) {
                int v = edge.destination;
                int weight = edge.weight;

                // Если найден более короткий путь до вершины v через текущую вершину u,
                // то обновляем расстояние до вершины v и добавляем ее в приоритетную очередь
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
    }

    return distance[9];
}

// Алгоритм Флойда-Уоршела:

// Функция для поиска длины кратчайшего пути от вершины 0 до вершины 9 с помощью алгоритма Флойда-Уоршела
int floydWarshall(vector<Edge> edges, int numVertices) {
    // Создаем матрицу расстояний между всеми парами вершин графа
    vector<vector<int>> distance(numVertices, vector<int>(numVertices, INT_MAX));

    // Заполняем матрицу расстояний известными значениями
    for (auto edge : edges) {
        distance[edge.source][edge.destination] = edge.weight;
    }

    // Проходим по всем парам вершин и обновляем расстояние через промежуточную вершину,
    // если это уменьшает текущее расстояние
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX && distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    return distance[0][9];
}

// Алгоритм Форда-Беллмана:
// Функция для поиска длины кратчайшего пути от вершины 0 до вершины 9 с помощью алгоритма Форда-Беллмана
int bellmanFord(vector<Edge> edges, int numVertices) {
    // Создаем вектор расстояний от вершины 0 до каждой другой вершины графа
    vector<int> distance(numVertices, INT_MAX);
    distance[0] = 0;

    // Проходим по всем ребрам графа numVertices - 1 раз и обновляем расстояния до всех вершин,
    // если найден более короткий путь через текущее ребро
    for (int i = 0; i < numVertices - 1; i++) {
        for (auto edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    return distance[9];
}

//Алгоритм A-star:

// Структура для представления вершины графа
struct Vertex {
    int id;
    int heuristic;
};

// Функция для поиска длины кратчайшего пути от вершины 0 до вершины 9 с помощью алгоритма A-star
int aStar(vector<Edge> edges, int numVertices) {
    // Создаем вектор вершин графа и задаем эвристическую функцию для каждой вершины
    vector<Vertex> vertices(numVertices);
    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].heuristic = abs(i - 9);
    }

    // Создаем вектор расстояний от вершины 0 до каждой другой вершины графа
    vector<int> distance(numVertices, INT_MAX);
    distance[0] = 0;

    // Создаем приоритетную очередь для хранения пар (расстояние + эвристика, вершина)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(distance[0] + vertices[0].heuristic, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Если достигнута вершина 9, то возвращаем расстояние до нее
        if (u == 9) {
            return distance[9];
        }

        // Проходим по всем ребрам, исходящим из текущей вершины
        for (auto edge : edges) {
            if (edge.source == u) {
                int v = edge.destination;
                int weight = edge.weight;

                // Если найден более короткий путь до вершины v через текущую вершину u,
                // то обновляем расстояние до вершины v и добавляем ее в приоритетную очередь
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v] + vertices[v].heuristic, v));
                }
            }
        }
    }

    return -1; // Если путь до вершины 9 не найден
}