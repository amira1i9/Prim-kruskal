#include "../include/utils.hpp"

void random_E_generator(int n, int W[10][10])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribution(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j)
            {
                int num = distribution(gen);
                W[i][j] = num;
                W[j][i] = num;
            }
            else
            {
                W[i][j] = 0;
            }
        }
    }
}

void kruskal(int n, set_of_edges E, set_of_edges &F)
{
    std::sort(E.begin(), E.end(), [](edge a, edge b)
              { return a.weight < b.weight; });
    F.clear();
    DisjointSet ds(n);
    for (const edge &e : E)
    {
        int i = e.u;
        int j = e.v;
        int p = ds.find(i);
        int q = ds.find(j);
        if (p != q)
        {
            ds.merge(p, q);
            F.push_back(e);
            if (static_cast<int>(F.size()) == n - 1)
            {
                break; // Minimum spanning tree found
            }
        }
    }
}

std::string prim(int n, int W[10][10])
{
    std::string answer;
    int vnear = 0;

    std::vector<int> nearest(n);
    std::vector<int> distances(n);

    for (int i = 1; i < n; i++)
    {
        nearest[i] = 0;
        distances[i] = W[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        double min = std::numeric_limits<int>::max();

        for (int j = 1; j < n; j++)
        {
            if (0 < distances[j] && distances[j] < min)
            {
                min = distances[j];
                vnear = j;
            }
        }

        answer = (std::to_string(vnear) + " - " + std::to_string(nearest[vnear]) + " : " + std::to_string(distances[vnear]) + "\n") + answer;

        distances[vnear] = -1;

        for (int j = 1; j < n; j++)
        {
            if ((W[j][vnear] < distances[j] || distances[j] == 0) && W[j][vnear] != 0)
            {
                distances[j] = W[j][vnear];
                nearest[j] = vnear;
            }
        }
    }

    return answer;
}