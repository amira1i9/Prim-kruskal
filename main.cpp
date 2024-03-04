#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

struct edge
    {
        int u, v, weight;
    };

typedef vector<edge> set_of_edges;

struct disjoint_set
    {
        vector<int> parent, rank;
        
        disjoint_set(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
    }
    
    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v)
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
            } else
                {
                    parent[rootU] = rootV;
                    rank[rootV]++;
                }
    }
};

//function alg kruskal batavajoh be shebhe code dakhel jozve
void kruskal(int n, int m, set_of_edges E, set_of_edges& F)
    {
        sort(E.begin(), E.end(), [](const edge& a, const edge& b)
             {
                return a.weight < b.weight;
             });

        F.clear();
        disjoint_set ds(n);

        for (const edge& e : E) {
            int i = e.u;
            int j = e.v;
            
            int p = ds.find(i);
            int q = ds.find(j);

            if (p != q) {
                ds.merge(p, q);
                F.push_back(e);

                if (F.size() == n - 1) {
                    break; // Minimum spanning tree found
                }
            }
        }
    }

//function alg prim ba tavajoh be shebhe code dakhel jozve
std::string prim(int n, int W[10][10])
    {
        string answer;
        int vnear = 0 ;
        

        int nearest[n];
        int distances[n];

        for (int i = 1; i < n; i++) {
            nearest[i] = 0;
            distances[i] = W[0][i];
        }
        
        

        for (int i = 1; i < n; i++)
        {
            double min = std::numeric_limits<int>::max();
            
            for (int j = 1; j < n; j++)
            {
                if ( 0 < distances[j] && distances[j] < min)
                    {
                        min = distances[j];
                        vnear = j;
                    }
            }
            
            answer = ( std::to_string(vnear) + " - " + std::to_string( nearest[vnear] ) + " : " + std::to_string(distances[vnear]) +"\n") + answer;
            
            distances[vnear] = -1;
            
            for (int j = 1; j < n; j++)
            {
                if ( (W[j][vnear] < distances[j] || distances[j] == 0) && W[j][vnear]!=0 )
                    {
                    distances[j] = W[j][vnear];
                    nearest[j] = vnear;
                    }
            }
            
        }
        
        return answer;
    }

// function baraye dorost kardan yek graph
void random_E_generator(int n , int W[10][10])
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distribution(0, n-1);
        
        for(int i =0 ; i<n; i++)
            for(int j =i; j<n;j++)
            {
                if(i!=j)
                    {
                    int num =distribution(gen);
                        W[i][j] = num;
                        W[j][i] = num;
                    }
                else
                    W[i][j]=0;
            }
    }

int main()
    {
        string answer;
        int n = 10; // Number of vertices for kruskal
        int m = 0; // Number of edges for kruskal
        
        int W[10][10];
        random_E_generator(10,W);
        
        // for kruskal

            set_of_edges E; // for sending edges info for kruskal
            set_of_edges F; // for kruskal answer
        
        for(int i=0; i<10;i++)
            for(int j = i; j<10; j++)
            {
                if(W[i][j]!=0)
                    {
                        E.push_back({i,j, W[i][j]});
                        E.push_back({j,i, W[i][j]});
                        n++;
                    }
        }

    cout <<"\nkruskal runtime : ";
    auto start1 = std::chrono::high_resolution_clock::now();
    kruskal(n, m, E, F);
    auto stop1 = std::chrono::high_resolution_clock::now();
    
    auto duration1 = std::chrono::duration_cast<std::chrono::duration<float>>(stop1 - start1);
    cout<<duration1.count()<<endl;
        
    // for kruskal

    
    cout <<"\nprim runtime : ";
    auto start2 = std::chrono::high_resolution_clock::now();
    answer = prim(10, W);
    auto stop2 = std::chrono::high_resolution_clock::now();
    
    auto duration2 = std::chrono::duration_cast<std::chrono::duration<float>>(stop2 - start2);
    cout<<duration2.count()<<endl<<endl;

    cout << "Edges in the Minimum Spanning Tree Kruskal:" << endl;
    for (const edge& e : F) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "\nEdges in the Minimum Spanning Tree Prim:" << endl;
    cout<<answer;

    return 0;
}
