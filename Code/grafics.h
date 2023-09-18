#ifndef CODE_GRAFICS_H
#define CODE_GRAFICS_H

#include "algorithm.h"
#include "generator.h"
#include <fstream>
#include <string>

void createGraphicTimeToVertex(vector<Algorithm> algorithms,  vector<string> names);
void createGraphicTimeToVertexAll(vector<Algorithm> algorithms);
void createGraphicTimeToEdges(vector<Algorithm> algorithms,  vector<string> names);
void createGraphicTimeToEdgesAll(vector<Algorithm> algorithms);

#endif //CODE_GRAFICS_H
