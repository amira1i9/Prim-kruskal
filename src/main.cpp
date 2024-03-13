#include <iostream>
#include <chrono>
#include "../include/utils.hpp"

int main()
{
    std::string answer;
    int n = 10; // Number of vertices for kruskal

    int W[10][10] = {0};
    random_E_generator(10, W);

    // for kruskal

    set_of_edges E; // for sending edges info for kruskal
    set_of_edges F; // for kruskal answer

    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
        {
            if (W[i][j] != 0)
            {
                E.push_back({i, j, W[i][j]});
                E.push_back({j, i, W[i][j]});
                n++;
            }
        }

    std::cout << "\nkruskal runtime : ";
    auto start1 = std::chrono::high_resolution_clock::now();
    kruskal(n, E, F);
    auto stop1 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::duration<float>>(stop1 - start1);
    std::cout << duration1.count() << std::endl;

    // for kruskal

    std::cout << "\nprim runtime : ";
    auto start2 = std::chrono::high_resolution_clock::now();
    answer = prim(10, W);
    auto stop2 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::duration<float>>(stop2 - start2);
    std::cout << duration2.count() << std::endl
              << std::endl;

    std::cout << "Edges in the Minimum Spanning Tree Kruskal:" << std::endl;
    for (const edge &e : F)
    {
        std::cout << e.u << " - " << e.v << " : " << e.weight << std::endl;
    }
    std::cout << "\nEdges in the Minimum Spanning Tree Prim:" << std::endl;
    std::cout << answer;

    return 0;
}
