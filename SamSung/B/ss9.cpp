#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int> > adj;

    Graph(int v) : V(v), adj(V);

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        for(int u : adj[v]) {
            if(!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(V, false);

        int i;
        for(i = 0; i < V; i++) {
            if(adj[i].size() > 0) {
                break;
            }
        }

        if(i == V) {
            return true;
        }
        
    }

};

int main() {

}