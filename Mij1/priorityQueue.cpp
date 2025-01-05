#include <iostream>
using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data;     // The value of the element
        int priority; // The priority of the element
    };

    Node* arr;      // Array to store the queue elements
    int capacity;   // Maximum size of the priority queue
    int size;       // Current number of elements in the queue

public:
    // Constructor to initialize the priority queue
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        arr = new Node[capacity];
        size = 0; // Initially, the queue is empty
    }

    // Destructor to free allocated memory
    ~PriorityQueue() {
        delete[] arr;
    }

    // Enqueue: Add an element with a priority
    void enqueue(int value, int priority) {
        if (isFull()) {
            cout << "Priority queue overflow! Cannot enqueue " << value << endl;
            return;
        }

        // Insert the new element at the end
        int i = size; // Start at the end of the queue
        while (i > 0 && arr[i - 1].priority < priority) {
            // Shift elements with lower priority to make space for the new element
            arr[i] = arr[i - 1];
            i--;
        }

        // Insert the new element at the correct position
        arr[i].data = value;
        arr[i].priority = priority;
        size++; // Increment the size
    }

    // Dequeue: Remove the element with the highest priority
    int dequeue() {
        if (isEmpty()) {
            cout << "Priority queue underflow! Cannot dequeue." << endl;
            return -1; // Return -1 to indicate failure
        }

        // The element at the front of the queue has the highest priority
        int value = arr[0].data;

        // Shift all elements to the left
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--; // Decrement the size
        return value;
    }

    // Peek: View the element with the highest priority without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Priority queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[0].data; // The front element has the highest priority
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return size == 0; // Empty when size is 0
    }

    // Check if the priority queue is full
    bool isFull() {
        return size == capacity; // Full when size equals capacity
    }

    // Display the elements of the priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority queue is empty!" << endl;
            return;
        }
        cout << "Priority queue elements (data, priority): ";
        for (int i = 0; i < size; i++) {
            cout << "(" << arr[i].data << ", " << arr[i].priority << ") ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(5); // Create a priority queue with a capacity of 5

    pq.enqueue(10, 2); // Enqueue 10 with priority 2
    pq.enqueue(20, 5); // Enqueue 20 with priority 5
    pq.enqueue(15, 3); // Enqueue 15 with priority 3
    pq.enqueue(30, 1); // Enqueue 30 with priority 1

    pq.display(); // Output: Priority queue elements: (20, 5) (15, 3) (10, 2) (30, 1)

    cout << "Dequeued: " << pq.dequeue() << endl; // Output: Dequeued: 20
    pq.display(); // Output: Priority queue elements: (15, 3) (10, 2) (30, 1)

    cout << "Peek: " << pq.peek() << endl; // Output: Peek: 15

    pq.enqueue(25, 4); // Enqueue 25 with priority 4
    pq.display(); // Output: Priority queue elements: (25, 4) (15, 3) (10, 2) (30, 1)

    return 0;
}
