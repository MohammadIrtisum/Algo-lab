#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int idx) {
        int parent = (idx - 1) / 2;

        if (idx > 0 && heap[idx] < heap[parent]) {
            swap(heap[idx], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
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
    MinHeap h;

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);

    cout << "Min-Heap array: ";
    h.displayHeap();

    cout << "Extracted min: " << h.extractMin() << endl;

    cout << "Min-Heap array after extracting min: ";
    h.displayHeap();

    return 0;
}
