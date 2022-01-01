#ifndef DATA_STRUCTURES_ADJACENCYMATRIX_H
#define DATA_STRUCTURES_ADJACENCYMATRIX_H

#include <iostream>
#include <vector>

class AdjacencyMatrix
{
    friend std::ostream &operator<<(std::ostream&, const AdjacencyMatrix&);
public:
    unsigned int n;
    std::vector<std::vector<bool>> a;
    AdjacencyMatrix();
    explicit AdjacencyMatrix(unsigned int);
    void addEdge(unsigned int, unsigned int);
    void removeEdge(unsigned int, unsigned int);
    bool hasEdge(unsigned int, unsigned int) const;
    std::vector<unsigned int> outEdges(unsigned int) const;
    std::vector<unsigned int> inEdges(unsigned int) const;
};


#endif //DATA_STRUCTURES_ADJACENCYMATRIX_H
