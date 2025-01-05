#include <iostream>
#include <stdexcept> // For exception handling

class MyVector {
private:
    int* data;       // Pointer to the array that stores elements
    int capacity;    // Current capacity of the vector
    int size;        // Current number of elements in the vector

public:
    // Constructor to initialize the vector with a specific capacity
    MyVector(int initialCapacity = 10) {
        size = 0;
        capacity = initialCapacity;
        data = new int[capacity];  // Dynamically allocate memory for the vector
    }

    // Destructor to free dynamically allocated memory
    ~MyVector() {
        delete[] data;
    }

    // Function to add an element at the end of the vector
    void push_back(int value) {
        if (size == capacity) { // Resize if the vector is full
            resize(capacity * 2);
        }
        data[size] = value;
        size++;
    }

    // Function to remove the last element
    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        size--;
    }

    // Function to get the element at a specific index
    int at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Function to get the number of elements in the vector
    int getSize() {
        return size;
    }

    // Function to get the capacity of the vector
    int getCapacity() {
        return capacity;
    }

    // Function to check if the vector is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to print the vector elements
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // Private function to resize the vector when it is full
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];  // Allocate new memory with increased capacity

        // Copy old data to new memory
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data;  // Free the old memory
        data = newData;  // Point to the new memory
        capacity = newCapacity;  // Update the capacity
    }
};

int main() {
    // Create a vector with an initial capacity of 5
    MyVector vec(5);

    // Add elements to the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    // Print the vector
    std::cout << "Vector elements: ";
    vec.print();

    // Add another element, triggering a resize
    vec.push_back(60);
    std::cout << "Vector after adding one more element: ";
    vec.print();

    // Access an element by index
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    // Remove the last element
    vec.pop_back();
    std::cout << "Vector after pop_back: ";
    vec.print();

    return 0;
}
