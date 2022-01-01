#include "AdjacencyMatrix.h"

using namespace std;

AdjacencyMatrix::AdjacencyMatrix()
{
    n = 0;
}

AdjacencyMatrix::AdjacencyMatrix(unsigned int n)
{
    this->n = n;
    for(unsigned int i = 0; i < n; ++i)
        a.push_back(vector<bool>(n, false));
}

void AdjacencyMatrix::addEdge(unsigned int i, unsigned int j)
{
    a[i][j] = true;
}

void AdjacencyMatrix::removeEdge(unsigned int i, unsigned int j)
{
    a[i][j] = false;
}

bool AdjacencyMatrix::hasEdge(unsigned int i, unsigned int j) const
{
    return a[i][j];
}

vector<unsigned int> AdjacencyMatrix::outEdges(unsigned int i) const
{
    vector<unsigned int> res;
    for(unsigned int j = 0; j < n; ++j)
        if(a[i][j])
            res.push_back(j);
    return res;
}

vector<unsigned int> AdjacencyMatrix::inEdges(unsigned int i) const
{
    vector<unsigned int> res;
    for(unsigned int j = 0; j < n; ++j)
        if(a[j][i])
            res.push_back(j);
    return res;
}

ostream &operator<<(ostream &output, const AdjacencyMatrix &a)
{
    for(unsigned int i = 0; i < a.n; ++i)
        for(unsigned int j = 0; j < a.n; ++j)
            if(a.a[i][j])
                cout << i << " --> " << j << endl;
    return output;
}