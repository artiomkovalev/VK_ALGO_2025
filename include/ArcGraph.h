#pragma once

#include "IGraph.h"
#include <vector>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int size);
    explicit ArcGraph(const IGraph &other);
    
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    
    struct Edge {
        int from;
        int to;
    };
    
    int verticesCount;
    std::vector<Edge> edges;
};
