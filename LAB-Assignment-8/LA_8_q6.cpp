#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } 
            else break;
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxVal;
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(20);
    pq.insert(80);
    pq.insert(60);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Max Element: " << pq.getMax() << endl;

    cout << "Extracted Max: " << pq.extractMax() << endl;

    cout << "After Extract: ";
    pq.display();

    return 0;
}
