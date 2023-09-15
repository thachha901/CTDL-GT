#include <iostream>

using namespace std;

void samePair(int a[], int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j]){
                count++;
            }
        }
    }
    cout << count << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    samePair(a, n);
    
}