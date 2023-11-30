#include <iostream>
#include <vector>

using namespace std;

#define M 10
#define N 10

bool canFill(int screen[M][N], int x, int y,int targetColor, int newColor) {
    if (x < 0 || x >= M ||y < 0 || y >= N) return false;

    if(screen[x][y] != targetColor) {
        return false;
    }

    if(screen[x][y] == newColor) {
        return false;
    }

    return true;
}

void floodFillUtil(int screen[M][N], int x, int y, int targetColor, int newColor) {

    if(!canFill(screen, x, y, targetColor, newColor)) {
        return;
    }

    screen[x][y] = newColor;

    floodFillUtil(screen, x + 1, y, targetColor, newColor);
    floodFillUtil(screen, x - 1, y, targetColor, newColor);
    floodFillUtil(screen, x, y - 1, targetColor, newColor);
    floodFillUtil(screen, x, y + 1, targetColor, newColor);
}

void floodFill(int screen[M][N], int x, int y, int newColor) {
    int targetColor = screen[x][y];
    floodFillUtil(screen, x, y, targetColor, newColor);
}

void print(int screen[M][N]) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    int screen[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> screen[i][j];
        }
    }

    int x = 4, y = 4, newColor = 3;

    print(screen);

    floodFill(screen, x, y, newColor);

    print(screen);
}