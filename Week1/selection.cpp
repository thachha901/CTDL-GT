#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void selectionSort(int a[], int n){
    int i, j, min;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    selectionSort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}