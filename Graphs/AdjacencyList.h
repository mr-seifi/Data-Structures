#ifndef DATA_STRUCTURES_ADJACENCYLIST_H
#define DATA_STRUCTURES_ADJACENCYLIST_H

#include "ArrayStack.cpp"

class AdjacencyList
{
    friend std::ostream &operator<<(std::ostream&, AdjacencyList&);
public:
    unsigned int n;
    ArrayStack<ArrayStack<unsigned int>> adj;
    AdjacencyList();
    explicit AdjacencyList(unsigned int);
    void addEdge(unsigned int, unsigned int);
    void addSimpleEdge(unsigned int, unsigned int);
    void removeEdge(unsigned int, unsigned int);
    bool hasEdge(unsigned int, unsigned int) const;
    ArrayStack<unsigned int> outEdges(unsigned int) const;
    ArrayStack<unsigned int> inEdges(unsigned int) const;
};


#endif //DATA_STRUCTURES_ADJACENCYLIST_H
