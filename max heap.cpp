#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> heap;


    void heapifyDown(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        
        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            heapifyDown(largest);
        }
    }

    
    void heapifyUp(int idx) {
        int parent = (idx - 1) / 2;

        if (idx > 0 && heap[idx] > heap[parent]) {
            swap(heap[idx], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.size() == 0)
            return -1;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    void displayHeap() {
        for (int i = 0; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    cout << "Max-Heap array: ";
    h.displayHeap();

    cout << "Extracted max: " << h.extractMax() << endl;

    cout << "Max-Heap array after extracting max: ";
    h.displayHeap();

    return 0;
}
