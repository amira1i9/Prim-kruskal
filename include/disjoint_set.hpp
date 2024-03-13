#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <vector>

class DisjointSet {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    public:
        DisjointSet(int n);
        int find(int u);
        void merge(int u, int v);
};

#endif