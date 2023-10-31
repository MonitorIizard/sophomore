#include <iostream>

using namespace std;

class Node {
public:
    int key;
    string value;

    Node(int k, const string& v) : key(k), value(v) {}
};

class StudentHashTable {
private:
    static const int ARRAYSIZE = 20;
    Node* hashTable[ARRAYSIZE] = { NULL };

    unsigned long hashFunction(const string& key) {
        string trimmedKey = key.substr(1);
        int i = 0;
        int sum = key[0] - '4';
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

public:
    void insert(const string& key) {
        unsigned long hashValue = hashFunction(key);
        unsigned long index = hashValue;
        int count = 1;

        while (count <= ARRAYSIZE) {
            if (hashTable[index] == NULL) {
                hashTable[index] = new Node(hashValue, key);
                cout << "Value " << key << " is stored at index " << index << endl;
                return;
            }
            index = quadraticProbe(hashValue, count);
            count++;
        }

        cout << "Unable to insert value " << key << ". Hash table is full." << endl;
    }

    void remove(const string& key) {
        unsigned long hashValue = hashFunction(key);
        unsigned long index = hashValue;
        int count = 1;

        while (count <= ARRAYSIZE) {
            if (hashTable[index] != NULL && hashTable[index]->key == hashValue) {
                Node* temp = hashTable[index];
                hashTable[index] = NULL;
                delete temp;
                cout << "Deleted value " << key << " at index " << index << endl;
                return;
            }
            index = quadraticProbe(hashValue, count);
            count++;
        }

        cout << "Value " << key << " not found." << endl;
    }

    void find(const string& key) {
        unsigned long hashValue = hashFunction(key);
        unsigned long index = hashValue;
        int count = 1;

        while (count <= ARRAYSIZE) {
            if (hashTable[index] != NULL && hashTable[index]->key == hashValue) {
                cout << "Found value " << key << " at index " << index << endl;
                return;
            }
            index = quadraticProbe(hashValue, count);
            count++;
        }

        cout << "Value " << key << " not found." << endl;
    }

    ~StudentHashTable() {
        for (int i = 0; i < ARRAYSIZE; ++i) {
            if (hashTable[i] != nullptr) {
                delete hashTable[i];
            }
        }
    }
};

int main() {
    StudentHashTable studentHashTable;

    studentHashTable.insert("6504062620060");
    studentHashTable.find("6504062620060");
    studentHashTable.insert("6504062620061");
    studentHashTable.insert("6504062620062");
    studentHashTable.remove("6504062620060");

    return 0;
}
