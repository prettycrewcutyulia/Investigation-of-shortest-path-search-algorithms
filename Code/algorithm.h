#ifndef CODE_ALGORITHM_H
#define CODE_ALGORITHM_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "struct.h"

typedef int (*Algorithm)(vector<Edge> edges, int numVertice);

int dijkstra(vector<Edge> edges, int numVertices);
int floydWarshall(vector<Edge> edges, int numVertices);
int bellmanFord(vector<Edge> edges, int numVertices);
int aStar(vector<Edge> edges, int numVertices);

#endif //CODE_ALGORITHM_H
