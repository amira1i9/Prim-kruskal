#include "../include/disjoint_set.hpp"

DisjointSet::DisjointSet(int n)
{
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
}

int DisjointSet::find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void DisjointSet::merge(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    if (rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootU] = rootV;
        rank[rootV]++;
    }
}