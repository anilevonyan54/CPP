#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;      // Array to store heap elements
    int capacity;    // Maximum capacity of the heap
    int size;        // Current size of the heap

    // Helper functions to get indices of parent and children
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    // Heapify Up: Maintain the heap property when inserting
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Heapify Down: Maintain the heap property after removing root
    void heapifyDown(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor to initialize heap with a fixed capacity
    MaxHeap(int cap) : capacity(cap), size(0) {
        heap = new int[capacity];  // Dynamically allocate memory for heap
    }

    // Destructor to free memory
    ~MaxHeap() {
        delete[] heap;
    }

    // Insert an element into the heap
    void insert(int value) {
        if (size >= capacity) {
            cout << "Heap is full!" << endl;
            return; // Do nothing if heap is full
        }

        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    // Remove and return the root element (maximum)
    int remove() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1; // Return -1 or any value indicating failure
        }

        int root = heap[0];
        heap[0] = heap[size - 1]; // Replace root with the last element
        size--;
        heapifyDown(0);  // Restore the heap property
        return root;
    }

    // Get the maximum element (root)
    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return -1; // Return -1 indicating empty heap
        }
        return heap[0];
    }

    // Print the elements of the heap
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10); // Create a max-heap with a capacity of 10

    // Insert elements into the heap
    maxHeap.insert(50);
    maxHeap.insert(30);
    maxHeap.insert(70);
    maxHeap.insert(20);

    // Print the heap
    cout << "Heap elements: ";
    maxHeap.printHeap();

    // Remove and print the maximum element
    cout << "Removed max: " << maxHeap.remove() << endl;

    // Print the heap after removal
    cout << "Heap after removal: ";
    maxHeap.printHeap();

    // Get and print the current maximum element
    cout << "Current max: " << maxHeap.getMax() << endl;

    return 0;
}
