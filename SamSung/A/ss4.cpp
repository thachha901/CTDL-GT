#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V; 
    std::vector<std::list<int> > adj; 

    bool isCyclicUtil(int v, std::vector<bool>& visited, std::vector<int>& parent, int& cycleLength);

public:
    Graph(int V);
    void addEdge(int v, int w);
    int getCycleLength();
    
    bool isBipartite();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, std::vector<bool>& visited, std::vector<int>& parent, int& cycleLength) {
    visited[v] = true;

    for (const auto& i : adj[v]) {
        if (!visited[i]) {
            parent[i] = v;
            if (isCyclicUtil(i, visited, parent, cycleLength))
                return true;
        } else if (parent[v] != i) {
            cycleLength = 1;
            int cur = v;

            while (cur != i) {
                cur = parent[cur];
                cycleLength++;
            }

            return true;
        }
    }

    return false;
}

int Graph::getCycleLength() {
    std::vector<bool> visited(V, false);
    std::vector<int> parent(V, -1);
    int cycleLength = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, parent, cycleLength))
                return cycleLength;
        }
    }

    return 0;
}

bool Graph::isBipartite() {
    std::vector<int> color(V, -1);

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            std::list<int> queue;
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
    
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    int cycleLength = g.getCycleLength();
    

    if(g.isBipartite()) {
        if(cycleLength >= 3 && cycleLength % 2 != 0) {
            cout << "Do thi co hai mau va co chu trinh le" << endl;
        } else {
            cout << "Do thi hai mau nhung khong co chu trinh le" << endl;
        }
    }

    Graph gr(5);
    gr.addEdge(0, 1);
    gr.addEdge(1, 2);
    gr.addEdge(2, 0);
    gr.addEdge(3, 0);
    gr.addEdge(4, 3);

    int cycleLength1 = gr.getCycleLength();

    if(cycleLength1 >= 3 && cycleLength1 % 2 != 0) {
        if(gr.isBipartite()) {
            cout << "Do thi co hai mau va co chu trinh le" << endl;
        } else {
            cout << "Do thi khong phai do thi hai mau nhung co chu trinh le" << endl;
        }
    }

    return 0;
}
