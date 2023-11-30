#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<list<int> > adj;

    bool isCycleUtil(int v, vector<bool>& visited, int parent);

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCycle();

    bool isBipartite();
};

bool Graph::isCycleUtil(int v, vector<bool>& visited, int parent) {
    visited[v] = true;

    for(auto& i: adj[v]) {
        if(!visited[i]) {
            if(isCycleUtil(i, visited, parent)) {
                return true;
            }
        } else if( i != parent) {
            return true;
        }
    }

    return false;
}

bool Graph::isCycle() {
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(isCycleUtil(i, visited, -1)) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isBipartite() {

    vector<int> color(V, -1);

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            list<int> queue;
            queue.push_back(i);
            color[i] = 0;

            while (!queue.empty()) {
                int u = queue.front();
                queue.pop_front();

                for (const auto& v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        queue.push_back(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    Graph gr(5);

    gr.addEdge(0, 1);
    gr.addEdge(0, 2);
    gr.addEdge(1, 3);
    gr.addEdge(2, 4);

    if(gr.isBipartite()) {
        if(gr.isCycle()) {
            cout << "Đồ thị là đồ thị hai màu và có chu trình lẻ." << endl;
        } else {
            cout << "Đồ thị là đồ thị hai màu nhưng không có chu trình lẻ." << endl;
        }
    } else {
        if(gr.isCycle()) {
            cout << "Đồ thị không phải đồ thị hai màu nhưng có chu trình lẻ." << endl;
        } else {
            cout << "Đồ thị không phải đồ thị hai màu và không có chu trình lẻ." << endl;
        }
    }

    return 0;
}