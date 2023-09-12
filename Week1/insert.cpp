#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int i, key, j;
    int count = 0;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while(key < arr[j] && j >= 0){
                arr[j + 1] = arr[j];
                --j;
                count++;
        }
        arr[j+1] = key;
    }

    cout << count << endl;

    return 0;
}