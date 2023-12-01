#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isEdge(int u, int v) {
        for(auto adj : adj[u]) {
            if(adj == v) {
                return true;
            }
        }

        return false;
    }

    void topologicalUtil(int v, bool visited[], stack<int>& st, vector<int>& res) {
        visited[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if(!visited[*i]) {
                topologicalUtil(*i, visited, st, res);
            }
        }

        st.push(v);
        res.push_back(v);
    }

    bool hasHamilton(vector<int> st) {
        for(int i = 0; i < st.size(); i++) {
            if(isEdge(st[i], st[i+1])) {
                return true;
            }
        }
        return false;
    }

    void topological() {
        stack<int> st;

        vector<int> res;

        bool* visited = new bool[V];

        for(int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                topologicalUtil(i, visited, st, res);
            }
        }

        if(hasHamilton(res)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topological();
}