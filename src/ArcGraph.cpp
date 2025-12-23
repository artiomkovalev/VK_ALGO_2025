#include "../include/ArcGraph.h"

ArcGraph::ArcGraph(int size)
: verticesCount(size) {};

ArcGraph::ArcGraph(const IGraph &other)
: verticesCount(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> nextVertices = other.GetNextVertices(i);
        for (int to : nextVertices) {
            AddEdge(i, to);
        };
    };
};

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({ from, to });
};

int ArcGraph::VerticesCount() const {
    return verticesCount;
};

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].from == vertex) {
            result.push_back(edges[i].to);
        };
    };
    return result;
};

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].to == vertex) {
            result.push_back(edges[i].from);
        };
    };
    return result;
};
