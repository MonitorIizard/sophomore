#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define ARRAYSIZE 20
#define STUDENT_ID_SIZE 14

unsigned long secondHashFunction(char* key) {
    unsigned long hashValue = 0;

    while (*key != '\0') {
        hashValue += *key;
        key++;
    }
    if (hashValue == 0) {
        hashValue = 1;
    }
    return hashValue;
}

unsigned long hashFunction(char* key) {
    key += 1;
    int i = 0;
    int sum = 0;
    string s;

    while (*key != '\0') {
        if (i == 4) {
            int num = 0;
            for (char c : s) {
                num = num * 10 + (c - '0');
            }
            sum += num;
            i = 0;
            s.clear();
        } else {
            s += *key;
            key += 1;
            i++;
        }
    }

    if (!s.empty()) {
        int num = 0;
        for (char c : s) {
            num = num * 10 + (c - '0');
        }
        sum += num;
    }

    unsigned long hashValue = sum % ARRAYSIZE;
    unsigned long step = secondHashFunction(key);
    unsigned long index = hashValue;

    // Double hashing loop to handle collisions
    while (*key != '\0') {
        // Update the index using the step size
        index = (index + step) % ARRAYSIZE;

       
    }

    return index;
}

int main() {
    char command;
    char key[STUDENT_ID_SIZE];
    unsigned long index;

    // Initialize your hash table and slotOccupied array here
    bool slotOccupied[ARRAYSIZE] = {false}; // Initialize all slots as unoccupied

    while (true) {
        cout << "Enter command (i for insert, d for delete, f for find, q for quit): ";
        cin >> command;

        if (command == 'q') {
            break;
        }

        switch (command) {
            case 'i':
                cout << "Enter key to insert: ";
                cin >> key;
                index = hashFunction(key);
    
                slotOccupied[index] = true; // Mark the slot as occupied
                break;
            case 'd':
                cout << "Enter key to delete: ";
                cin >> key;
                index = hashFunction(key);
                // Delete the key from the hash table at the calculated index
                slotOccupied[index] = false; // Mark the slot as unoccupied
                break;
            case 'f':
                cout << "Enter key to find: ";
                cin >> key;
                index = hashFunction(key);
                // Find the key in the hash table at the calculated index
                // Display whether the key is found or not
                if (slotOccupied[index]) {
                    cout << "Key found at index " << index << endl;
                } else {
                    cout << "Key not found" << endl;
                }
                break;
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }

    return 0;
}

