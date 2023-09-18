#include "generator.h"
#include "algorithm.h"
#include "grafics.h"

using namespace std;

int main() {
    std::vector<Algorithm> algorithms = {dijkstra, floydWarshall, bellmanFord, aStar};
    std::vector<std::string> names = {"Дейкстры", "Флойда-Уоршела", "Форда-Беллмана", "A-star"};
    createGraphicTimeToVertex(algorithms, names);
    std::cout << "Шаг1" << "\n";
    createGraphicTimeToVertexAll(algorithms);
    std::cout << "Шаг2" << "\n";
    createGraphicTimeToEdges(algorithms, names);
    std::cout << "Шаг3" << "\n";
    createGraphicTimeToEdgesAll(algorithms);
}
