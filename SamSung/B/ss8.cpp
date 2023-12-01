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

    void BFS(int u) {
        vector<bool> visited;
        visited.resize(V, false);

        list<int> queue;

        visited[u] = true;

        queue.push_back(u);

        while(!queue.empty()) {
            u = queue.front();
            cout << u << " ";

            queue.pop_front();

            for(auto adjacent : adj[u]) {
                if(!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
        cout << endl;
    }

    void topologicalUtil(int v, bool visited[], stack<int>& st) {
        visited[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if(!visited[*i]) {
                topologicalUtil(*i, visited, st);
            }
        }
        st.push(v);
    }

    void topological() {
        stack<int> st;
        bool* visited = new bool[V];
        for(int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                topologicalUtil(i, visited, st);
            }
        }  

        while(!st.empty()) {
            cout << st.top() << endl;
            st.pop();
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

    g.BFS(5); // BFS duyệt các đỉnh theo từng tầng 1 từ tầng đầu tiên đến các tầng cuối cùng
            //  nên không thể đảm bảo được thứ tự giôgns như Topological
            // Trong khi Topological Sort thì duyệt các đỉnh tương tự như DFS tức là duyệt
            // tất cả các cạnh kề với đỉnh cha


    g.topological();
}