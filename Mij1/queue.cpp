#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;      // Pointer to the array that holds the queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int capacity;  // Maximum capacity of the queue
    int size;      // Current number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;         // Initially, the front is at index 0
        rear = -1;         // Rear starts at -1 (queue is empty)
        size = 0;          // Initially, the queue is empty
    }

    // Destructor to clean up allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation: Add an element to the rear of the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Move rear to the next position (circular queue)
        arr[rear] = value;           // Add the value to the rear
        size++;                      // Increment the size
    }

    // Dequeue operation: Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue." << endl;
            return -1; // Return -1 to indicate failure
        }
        int value = arr[front];       // Get the value at the front
        front = (front + 1) % capacity; // Move front to the next position (circular queue)
        size--;                       // Decrement the size
        return value;
    }

    // Peek operation: View the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[front]; // Return the front element
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0; // Queue is empty when size is 0
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity; // Queue is full when size equals capacity
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " "; // Access elements in circular order
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5); // Create a queue with a capacity of 5

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Output: Queue elements: 10 20 30

    cout << "Front element: " << queue.peek() << endl; // Output: Front element: 10

    queue.dequeue();
    queue.display(); // Output: Queue elements: 20 30

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // This will work because the queue is circular
    queue.enqueue(70); // Overflow, as capacity is 5

    queue.display(); // Output: Queue elements: 20 30 40 50 60

    return 0;
}
