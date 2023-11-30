#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

#define NIL -1

class Graph{
    int V;
    list<int> *adj;

    bool isBCUtil(int v, bool visited[], int disc[], int low[], int parent[]);

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBC();
};

bool Graph::isBCUtil(int u, bool visited[], int disc[], int low[], int parent[]){
    static int time = 0;

    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;

        if(!visited[v]) {
            children++;
            parent[v] = u;

            if(isBCUtil(v, visited, disc, low, parent)) {
                return true;
            }

            low[u] = min(low[u], low[v]);

            if(parent[u] == -1 && children > 1) {
                return true;
            }

            if(parent[u] == -1 && low[v] > disc[u]) {
                return true;
            }
        }else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    return false;
}

bool Graph::isBC()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    if (isBCUtil(0, visited, disc, low, parent) == true)
        return false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;

    return true;
}

int main()
{
    Graph g1(2);
    g1.addEdge(0, 1);
    g1.isBC()? cout << "Yes\n" : cout << "No\n";
}