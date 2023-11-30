#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;
    int time;

    bool bridgeUtil(int u, vector<int>& disc, vector<int>& low, vector<int>& parent);

public:
    Graph(int V) {
        this->V = V;
        this->adj.resize(V);
        this->time = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int findBridge();
};

bool Graph::bridgeUtil(int u, vector<int>& disc, vector<int>& low, vector<int>& parent) {
    static int time = 0;
    disc[u] = low[u] = ++time;

    for(int v: adj[u]) {
        if (!disc[v]) {
            parent[v] = u;
            bridgeUtil(v, disc, low, parent);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                return true;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    return false;
}

int Graph::findBridge() {
    vector<int> disc(V, 0);
    vector<int> low(V, 0);
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) {
        if (!disc[i])

            return bridgeUtil(i, disc, low, parent);
    }

    return 0;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    if(g.findBridge() == 1) {
        cout << "There is a bridge" << endl;
    } else {
        cout << "There is a bridge" << endl;
    }

    return 0;
}