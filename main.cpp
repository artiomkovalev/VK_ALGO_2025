#include <iostream>
#include <vector>

#include "./include/ListGraph.h"
#include "./include/MatrixGraph.h"
#include "./include/SetGraph.h"
#include "./include/ArcGraph.h"

void PrintGraph(const IGraph &graph) {
    std::cout << "Vertices: " << graph.VerticesCount() << std::endl;
    for (int i = 0; i < graph.VerticesCount(); i++) {
        std::cout << i << ": ";
        std::vector<int> next = graph.GetNextVertices(i);
        for (int vertex : next) {
            std::cout << vertex << " ";
        };
        std::cout << std::endl;
    };
    std::cout << "----------------" << std::endl;
};

int main() {
    ListGraph listGraph(10);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(0, 3);
    listGraph.AddEdge(1, 4);
    listGraph.AddEdge(2, 5);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(3, 7);
    
    std::cout << "ListGraph:" << std::endl;
    PrintGraph(listGraph);
    
    MatrixGraph matrixGraph(listGraph);
    std::cout << "MatrixGraph:" << std::endl;
    
    SetGraph setGraph(matrixGraph);
    std::cout << "SetGraph:" << std::endl;
    PrintGraph(setGraph);
    
    ArcGraph arcGraph(setGraph);
    std::cout << "ArcGraph:" << std::endl;
    PrintGraph(arcGraph);
    
    return 0;
};
