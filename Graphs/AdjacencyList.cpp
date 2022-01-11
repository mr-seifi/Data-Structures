#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList()
{
    n = 0;
}

AdjacencyList::AdjacencyList(unsigned int n)
{
    this->n = n;
    adj = ArrayStack<ArrayStack<unsigned int>>(n);
}

void AdjacencyList::addEdge(unsigned int i, unsigned int j)
{
    adj[i].add(adj[i].size(), j);
}

void AdjacencyList::addSimpleEdge(unsigned int i, unsigned int j)
{
    addEdge(i, j);
    addEdge(j, i);
}

void AdjacencyList::removeEdge(unsigned int i, unsigned int j)
{
    adj[i].remove(adj[i].find(j));
}

bool AdjacencyList::hasEdge(unsigned int i, unsigned int j) const
{
    return adj[i].has(j);
}

ArrayStack<unsigned int> AdjacencyList::outEdges(unsigned int i) const
{
    ArrayStack<unsigned int> u;
    for(unsigned int k = 0; k < adj[i].size(); ++k)
        u.add(u.size(), adj[i][k]);
    return u;
}

ArrayStack<unsigned int> AdjacencyList::inEdges(unsigned int i) const
{
    ArrayStack<unsigned int> u;
    for(unsigned int j = 0; j < n; ++j)
        if(adj[j].has(i))
            u.add(u.size(), j);
    return u;
}

std::ostream &operator<<(std::ostream &output, AdjacencyList &a)
{
    for(unsigned int i = 0; i < a.n; ++i)
        for(unsigned int j = 0; j < a.adj[i].size(); ++j)
            output << i << " --> " << a.adj[i][j] << std::endl;
    return output;
}