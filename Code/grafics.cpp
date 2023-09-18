// построить графики зависимости отдельно по каждому алгоритму
// времени от числа вершин
#include "algorithm.h"
#include "generator.h"
#include <fstream>
#include <string>
typedef vector<Edge> (*gener)(int numVertices);

long long int time (vector<Edge> edges, int num, int (*Algorithm)(vector<Edge> edges, int numVertice)) {
    long long int duration;
    auto start = std::chrono::high_resolution_clock::now();
    Algorithm(edges, num);
    auto end = std::chrono::high_resolution_clock::now();
    duration = duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}

void createGraphicTimeToVertex(vector<Algorithm> algorithms,  vector<string> names) {
    for (int i = 0; i < 4; i++) {
        string filename = names[i] + ".csv";
        ofstream file(filename);
        file << names[i] << "\n";
        file << "Тип графа";
        for (int j = 10; j <= 1010; j += 50) {
            file << ";" << j;
        }
        file << "\n";
        file << "Полные графы";
        for (int j = 10; j < 1010; j += 50) {
            vector<Edge> edges = generateCompleteGraph(j);
            long long int duration = 0;
            for (int k = 0; k < 5; k++) {
                duration += time(edges, j, algorithms[i]);
            }
            file << ";" << duration / 5;
        }
        file << "\n";
        file << "Связные графы";
        for (int j = 10; j < 1010; j += 50) {
            vector<Edge> edges = generateConnectedGraph(j);
            long long int duration = 0;
            for (int k = 0; k < 5; k++) {
                duration += time(edges, j, algorithms[i]);
            }
            file << ";" << duration / 5;
        }
        file << "\n";
        file << "Разреженные графы";
        for (int j = 10; j < 1010; j += 50) {
            vector<Edge> edges = generateSparseGraph(j);
            long long int duration = 0;
            for (int k = 0; k < 5; k++) {
                duration += time(edges, j, algorithms[i]);
            }
            file << ";" << duration / 5;
        }
        file << "\n";
        file.close();
    }
}

void createGraphicTimeToVertexAll(vector<Algorithm> algorithms) {
    vector<string> gener_name = {"Полный", "Связный", "Разреженный"};
    vector<gener> gener = {generateCompleteGraph, generateSparseGraph, generateConnectedGraph};
    for (int j = 0; j < 3; j++) {
            string filename = gener_name[j] + ".csv";
            ofstream file(filename);
            file << gener_name[j] << "\n";
            file << "Кол-во вершин";
            file << ";Дейкстры;Флойда-Уоршела;Форда-Беллмана;A-star" << "\n";
            for (int k = 10; k <= 1010; k += 50) {
                file << k;
                vector<Edge> edges = generateConnectedGraph(k);
                for (int i = 0; i < 4; i++) {
                    long long int duration = 0;
                    for (int m = 0; m < 5; m++) {
                        duration += time(edges, k, algorithms[i]);
                    }
                    file << ";" << duration / 5;
                }
                file << "\n";
            }
        file.close();
    }
}
void createGraphicTimeToEdgesAll(vector<Algorithm> algorithms) {
    vector<string> gener_name = {"Полный", "Связный", "Разреженный"};
    vector<gener> gener = {generateCompleteGraph, generateConnectedGraph, generateSparseGraph};
    for (int j = 0; j < 3; j++) {
        string filename = gener_name[j] + "edges" + ".csv";
        ofstream file(filename);
        file << gener_name[j] << "\n";
        file << "Кол-во ребер";
        file << ";Дейкстры;Флойда-Уоршела;Форда-Беллмана;A-star" << "\n";
        for (int k = 10; k <= 1010; k += 50) {
            vector<Edge> edges = gener[j](k);
            file << edges.size() / 2;
            for (int i = 0; i < 4; i++) {
                long long int duration = 0;
                for (int m = 0; m < 5; m++) {
                    duration += time(edges, k, algorithms[i]);
                }
                file << ";" << duration / 5;
            }
            file << "\n";
        }
        file.close();
    }
}


void createGraphicTimeToEdges(vector<Algorithm> algorithms,  vector<string> names) {
    vector<string> gener_name = {"Полный", "Связный", "Разреженный"};
    vector<gener> gener = {generateCompleteGraph, generateConnectedGraph, generateSparseGraph};
    for (int j = 0; j < 4; j++) {
        string filename = names[j] + "edges" + ".csv";
        ofstream file(filename);
        file << names[j] << "\n";
        for (int t = 0; t < 3; t++) {
            file << "Кол-во ребер;" << gener_name[t] << "\n";
            for (int k = 10; k <= 1010; k += 50) {
                vector<Edge> edges = gener[t](k);
                file << edges.size() / 2;
                    long long int duration = 0;
                    for (int m = 0; m < 5; m++) {
                        duration += time(edges, k, algorithms[j]);
                    }
                    file << ";" << duration / 5;

                file << "\n";
            }
            file << "\n";
        }
        file.close();
    }
}
