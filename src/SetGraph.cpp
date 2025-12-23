#include "SetGraph.h"

SetGraph::SetGraph(int size)
: adjSets(size), prevAdjSets(size) {};

SetGraph::SetGraph(const IGraph &other)
: adjSets(other.VerticesCount()), prevAdjSets(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> nextVertices = other.GetNextVertices(i);
        for (int to : nextVertices) {
            AddEdge(i, to);
        };
    };
};

void SetGraph::AddEdge(int from, int to) {
    bool exists = false;
    for (int vertex : adjSets[from]) {
        if (vertex == to) {
            exists = true;
            break;
        };
    };
    if (!exists) {
        adjSets[from].push_back(to);
    };
    exists = false;
    for (int vertex : prevAdjSets[to]) {
        if (vertex == from) {
            exists = true;
            break;
        };
    };
    if (!exists) {
        prevAdjSets[to].push_back(from);
    };
};

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjSets.size());
};

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return adjSets[vertex];
};

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    return prevAdjSets[vertex];
};
