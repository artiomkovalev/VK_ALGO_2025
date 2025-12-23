#pragma once

#include "IGraph.h"
#include <vector>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int size);
    explicit MatrixGraph(const IGraph &other);
    
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() const override;
    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> matrix;
};
