#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

class Heap {
    int *arr;
    int size;
    int cap;

public:

    Heap(int cap) {
        size = 0;
        arr = new int[cap];
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int parent(int i) {
        return (i - 1 ) / 2;
    }


    void insert(int k) {
        size++;
        int i = size - 1;
        arr[i] = k;
        
        while(i != 0 && arr[i] > arr[parent(i)]){
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
    }

    void sink(int a[], int k, int size) {
        int max = k;
        if(left(k) < size && arr[left(k)] > arr[max]) {
            max = left(k);
        }

        if(right(k) < size && arr[right(k)] > arr[max]) {
            max = right(k);
        }

        if(max != k) {
            swap(&arr[max], &arr[k]);
            sink(arr, max, size);
        }
    }

    int remove_Max() {
        int max = arr[0];
        arr[0] = arr[--size];
        sink(arr, 0, size);
        return max;
    }

    int remove(int n) {
        int re = arr[n];
        arr[n] = arr[--size];
        sink(arr, n, size);
        return re;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap heap(11);
    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(10);
    heap.remove(3);

    heap.print();
    
}