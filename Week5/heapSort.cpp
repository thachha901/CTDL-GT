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

    void insert(int k) {
        int i = size;
        arr[i] = k;
        size++;
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

    void heapSort() {
        for(int i = size/2 - 1; i >= 0; i--) {
            sink(arr, i, size);
        }
        

        for(int i = size - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);

            sink(arr, 0, i);
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Heap heap(11);
    heap.insert(11);
    heap.insert(18);
    heap.insert(9);
    heap.insert(25);
    heap.insert(24);
    heap.insert(27);
    heap.insert(16);

    heap.heapSort();

    heap.print();
}