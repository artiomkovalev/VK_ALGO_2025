#include "../include/MatrixGraph.h"

MatrixGraph::MatrixGraph(int size)
: matrix(size, std::vector<int>(size, 0)) {};

MatrixGraph::MatrixGraph(const IGraph &other)
: matrix(other.VerticesCount(), std::vector<int>(other.VerticesCount(), 0)) {
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> nextVertices = other.GetNextVertices(i);
        for (int to : nextVertices) {
            AddEdge(i, to);
        };
    };
};

void MatrixGraph::AddEdge(int from, int to) {
    if (from < 0 || from >= matrix.size() || to < 0 || to >= matrix.size()) {
        return;
    };
    matrix[from][to] = 1;
};

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix.size());
};

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i] != 0) {
            result.push_back(i);
        };
    };
    return result;
};

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][vertex] != 0) {
            result.push_back(i);
        };
    };
    return result;
};
