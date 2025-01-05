#include <iostream>
#include <list>
using namespace std;

class HashSet {
private:
    static const int SIZE = 10;     // Fixed size of the hash table
    list<int> table[SIZE];          // Array of linked lists to handle collisions

    // Hash function to calculate the index
    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    // Insert an element into the hash set
    void insert(int key) {
        int index = hashFunction(key);       // Calculate the index
        for (int element : table[index]) {  // Check if the key already exists
            if (element == key) return;     // Do nothing if the key is already present
        }
        table[index].push_back(key);        // Add the key to the linked list
    }

    // Check if an element exists in the hash set
    bool contains(int key) {
        int index = hashFunction(key);      // Calculate the index
        for (int element : table[index]) {
            if (element == key) {
                return true;                // Key found
            }
        }
        return false;                       // Key not found
    }

    // Remove an element from the hash set
    void remove(int key) {
        int index = hashFunction(key);      // Calculate the index
        table[index].remove(key);           // Remove the key from the linked list
    }

    // Display the hash set
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            for (int element : table[i]) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashSet hs;

    // Insert elements
    hs.insert(10);
    hs.insert(20);
    hs.insert(30);
    hs.insert(25); // Collides with 20 (25 % 10 == 5)
    hs.insert(15);

    // Display the hash set
    hs.display();
    // Example output:
    // Index 0: 
    // Index 1: 
    // Index 2: 
    // Index 3: 
    // Index 4: 
    // Index 5: 25 15 
    // Index 6: 
    // Index 7: 
    // Index 8: 
    // Index 9: 10 20 30 

    // Check for elements
    cout << "Contains 20: " << (hs.contains(20) ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 40: " << (hs.contains(40) ? "Yes" : "No") << endl; // Output: No

    // Remove an element
    hs.remove(20);
    hs.display(); // Key 20 is removed

    return 0;
}
