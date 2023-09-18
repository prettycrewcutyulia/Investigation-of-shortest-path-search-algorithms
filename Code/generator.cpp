#include "struct.h"
#include "generator.h"

int maxWeight = 10;
//a. Полные графы:

vector<Edge> generateCompleteGraph(int numVertices) {
    vector<Edge> edges;
    srand(time(NULL));
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            int weight = rand() % maxWeight + 1;
            edges.push_back({i, j, weight});
            edges.push_back({j, i, weight});
        }
    }
    return edges;
}

// b. Связные графы с коэффициентом плотности приблизительно 0.4-0.5:

vector<Edge> generateConnectedGraph(int numVertices) {
    vector<Edge> edges;
    srand(time(NULL));
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (rand() % 10 < 5) {
                int weight = rand() % maxWeight + 1;
                edges.push_back({i, j, weight});
                edges.push_back({j, i, weight});
            }
        }
    }
    return edges;
}

// c. Разреженные графы (деревья):

vector<Edge> generateSparseGraph(int numVertices) {
    vector<Edge> edges;
    srand(time(NULL));
    for (int i = 1; i < numVertices; i++) {
        int parent = rand() % i;
        int weight = rand() % maxWeight + 1;
        edges.push_back({parent, i, weight});
        edges.push_back({i, parent, weight});
    }
    return edges;
}