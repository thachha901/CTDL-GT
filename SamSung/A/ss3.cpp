#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    vector<list<int> > adjList;

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int countParallel() {
        int count = 0;
        for (int i = 0; i < V; ++i) { 

            for (int neighbor : adjList[i]) { 

                for (int neighborOfNeighbor : adjList[neighbor]) { 

                    if (neighborOfNeighbor != i) { 

                        for (int secondNeighbor : adjList[i]) { 

                            if (secondNeighbor == neighborOfNeighbor) { 

                                ++count; 

                                break; 

                            } 

                        } 

                    } 

                } 
            }
        }

        return count / 2;
    }

};

int main() {
    Graph gr(4);
    gr.addEdge(0, 1);
    gr.addEdge(1, 2);
    gr.addEdge(2, 3);
    gr.addEdge(3, 0);
    gr.addEdge(0, 2);

    int res = gr.countParallel();

    cout << res << endl;

}