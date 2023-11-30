#include <iostream>

using namespace std;

int C(int k, int n) {
    if(k == 0 || k == n) return 1;
    if(k == 1) return n;

    return C(k - 1, n - 1) + C(k, n - 1);
}

int count(int V, int E) {
    return (C(E, C(2, V-1) + E));
}

int main() {
    int V, E;
    cin >> V >> E;

    cout << count(V, E) << endl;

}