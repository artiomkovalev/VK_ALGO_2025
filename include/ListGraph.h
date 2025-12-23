#pragma once

#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph {
public:
    explicit ListGraph(int size);
    explicit ListGraph(const IGraph &other);
    
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    
private:
    std::vector<std::vector<int>> adjLists;
    std::vector<std::vector<int>> prevAdjLists;
};
