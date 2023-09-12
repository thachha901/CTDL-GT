#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void quickSort(int a[], int left, int right){
    int mid = (left + right)/2;
    int pivot = a[mid];
    int i = left, j = right;
    while(i < j){
        while(a[i] < pivot){
            i++;
        }

        while(a[j] > pivot){
            --j;
        }

        if(i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }

    }

    if(i < right){
        quickSort(a, i, right);
    }

    if(left < j){
        quickSort(a, left ,j);
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


    
}