#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V; // Số đỉnh
    vector<vector<int> > adjList; // Danh sách liên kết lưu trữ đồ thị

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // Thêm cạnh vào đồ thị
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Đếm số đồ thị có hướng phi chu trình chứa V đỉnh
    int countDAGsWithVVertices() {
        // Tạo một mảng để lưu số lượng đường đi đến mỗi đỉnh
        vector<int> inDegree(V, 0);

        // Tính in-degree cho mỗi đỉnh
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjList[i]) {
                inDegree[neighbor]++;
            }
        }

        // Tính số lượng đồ thị có hướng phi chu trình chứa V đỉnh
        int count = 0;
        for (int i = 0; i < V; ++i) {
            // Nếu đỉnh hiện tại không có đỉnh nào trỏ vào (in-degree = 0),
            // thì có thể bắt đầu từ đỉnh này để tạo một DAG không chu trình
            if (inDegree[i] == 0) {
                count += countDAGsStartingFrom(i, inDegree);
            }
        }

        return count;
    }

private:
    // Hàm đệ quy để đếm số đồ thị có hướng phi chu trình bắt đầu từ một đỉnh cụ thể
    int countDAGsStartingFrom(int v, vector<int>& inDegree) {
        if (v == V - 1) {
            // Nếu đến đỉnh cuối cùng, trả về 1 vì đã tạo thành một DAG
            return 1;
        }

        int count = 0;

        // Giảm in-degree của các đỉnh kề và đệ quy
        for (int neighbor : adjList[v]) {
            inDegree[neighbor]--;
            count += countDAGsStartingFrom(neighbor, inDegree);
            inDegree[neighbor]++;
        }

        return count;
    }
};

int main() {
    // Tạo đồ thị với 4 đỉnh
    Graph graph(4);

    // Thêm các cạnh vào đồ thị
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    // Đếm số đồ thị có hướng phi chu trình chứa 4 đỉnh và in kết quả
    int count = graph.countDAGsWithVVertices();
    cout << "So do thi co huong phi chu trinh chua " << graph.V << " dinh la: " << count << endl;

    return 0;
}
