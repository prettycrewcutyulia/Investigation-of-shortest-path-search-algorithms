#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <vector>
#include <random>
#include "struct.h"

vector<Edge> generateCompleteGraph(int numVertices);
vector<Edge> generateConnectedGraph(int numVertices);
vector<Edge> generateSparseGraph(int numVertices);

#endif //CODE_GENERATOR_H
