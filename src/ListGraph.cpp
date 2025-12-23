#include "../include/ListGraph.h"

ListGraph::ListGraph(int size)
: adjLists(size), prevAdjLists(size) {};

ListGraph::ListGraph(const IGraph &other)
: adjLists(other.VerticesCount()), prevAdjLists(other.VerticesCount()) {
    for (int i = 0; i < other.VerticesCount(); i++) {
        std::vector<int> nextVertices = other.GetNextVertices(i);
        for (int to : nextVertices) {
            AddEdge(i, to);
        };
    };
};

void ListGraph::AddEdge(int from, int to) {
    adjLists[from].push_back(to);
    prevAdjLists[to].push_back(from);
};

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjLists.size());
};

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjLists[vertex];
};

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    return prevAdjLists[vertex];
};
