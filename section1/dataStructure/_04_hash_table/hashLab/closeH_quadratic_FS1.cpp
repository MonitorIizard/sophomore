#include <iostream>
#include <sstream>
#include <cstring> // for strlen
#include <string>
#include <unordered_map>

using namespace std;

#define ARRAYSIZE 20
#define STUDENT_ID_SIZE 14

unsigned long hashFunction(const string& key) {
    string trimmedKey = key.substr(1); // Remove the first character (command)
    int i = 0;
    int sum = key[0] - '4'; // Add the first character as an integer
    string s;

    for (char ch : trimmedKey) {
        if (i == 4) {
            sum += stoi(s);
            i = 0;
            s.clear();
        } else {
            s += ch;
            i++;
        }
    }

    sum += stoi(s);
    return sum % ARRAYSIZE;
}

unsigned long quadraticProbe(unsigned long hashValue, int attempt) {
    return (hashValue + attempt * attempt) % ARRAYSIZE;
}

void insertWithQuadraticProbing(int hashTable[], unsigned long hashValue) {
    unsigned long index = hashValue;
    int attempt = 1;

    while (index < ARRAYSIZE && attempt <= ARRAYSIZE) {
        if (hashTable[index] == 0) {
            hashTable[index] = hashValue;
            cout << "Student ID " << hashValue << " is stored at index " << index << endl;
            return;
        }
        index = quadraticProbe(hashValue, attempt);
        attempt++;
    }

    cout << "Unable to insert Student ID " << hashValue << ". Hash table is full." << endl;
}

int main() {
    string command;
    string input;

    int hashTable[ARRAYSIZE] = {0}; // Initialize the hash table with zeros

    while (true) {
        cout << "Enter command (In = Insert, De = Delete, Fi = Find, x = Exit): ";
        cin >> command;

        if (command == "In") {
            cout << "Enter student ID: ";
            cin >> input;
            unsigned long hashValue = hashFunction(input);
            insertWithQuadraticProbing(hashTable, hashValue);
        } else if (command == "De") {
            cout << "Enter student ID to delete: ";
            cin >> input;
            
            // Check if the student ID exists in the hash table
            unsigned long hashValue = hashFunction(input);
            unsigned long index = hashValue;
            int attempt = 1;

            while (index < ARRAYSIZE && attempt <= ARRAYSIZE) {
                if (hashTable[index] == hashValue) {
                    hashTable[index] = 0;
                    cout << "Deleted student ID " << input << " at index " << index << endl;
                    break;
                }
                index = quadraticProbe(hashValue, attempt);
                attempt++;
            }

            if (index >= ARRAYSIZE || attempt > ARRAYSIZE) {
                cout << "Student ID " << input << " not found." << endl;
            }
        } else if (command == "Fi") {
            cout << "Enter student ID to find: ";
            cin >> input;

            // Check if the student ID exists in the hash table
            unsigned long hashValue = hashFunction(input);
            unsigned long index = hashValue;
            int attempt = 1;

            while (index < ARRAYSIZE && attempt <= ARRAYSIZE) {
                if (hashTable[index] == hashValue) {
                    cout << "Found student ID " << input << " at index " << index << endl;
                    break;
                }
                index = quadraticProbe(hashValue, attempt);
                attempt++;
            }

            if (index >= ARRAYSIZE || attempt > ARRAYSIZE) {
                cout << "Student ID " << input << " not found." << endl;
            }
        } else if (command == "x") {
            break; // Exit the loop
        } else {
            cout << "Invalid command. Please enter In, De, Fi, or x." << endl;
        }
    }

    return 0;
}
