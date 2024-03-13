#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include "disjoint_set.hpp"

struct edge {
    int u, v, weight;
};

typedef std::vector<edge> set_of_edges;

void random_E_generator(int n, int W[10][10]);

void kruskal(int n, set_of_edges E, set_of_edges &F);

std::string prim(int n, int W[10][10]);

#endif