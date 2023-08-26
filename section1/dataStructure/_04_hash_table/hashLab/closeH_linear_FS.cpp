// โมกข์เเก้ int เป็น long นะ เพราะตัวเลขนักศึกษามัน bit เยอะกว่า int

#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    int size;
    vector<long> table;

public:
    HashTable(long size) : size(size), table(size, -1) {}

    long hash(long key) {
        return key % size;
    }

    int foldShiftHash(long key) {
        int hashValue = 0;
        int numChunks = 4; // Number of chunks for demonstration
        int round = 0;

        for (int i = 0; i < numChunks && round < 3; ++i , round++) {
            hashValue += key % 1000; // Extract a 3-digit chunk
            key /= 1000;
            cout << hashValue << endl;
        }

        return hashValue % size;
    }

    void insert(long key) {
        int index = foldShiftHash(key);
        int originalIndex = index;

        while (table[index] != -1) {
            index = (index + 1) % size; // Linear probing: f(i) = i
            if (index == originalIndex) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        table[index] = key;
    }

    void remove(long key) {
        //! int index = hash(key);
        int index = foldShiftHash(key);
        int originalIndex = index; //19

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -5; // Mark the slot as empty to delete the key
                cout << "Key " << key << " deleted." << endl;
                return;
            }

            index = (index + 1) % size; // Linear probing: f(i) = i
            if (index == originalIndex) {
                cout << "Key not found." << endl;
                return;
            }
        }

        cout << "key is not found" << endl;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else if ( table[i] == -1 ) {
                cout << "-free" << endl;
            }
        }
    }

    void find( long key ) {
        int index = foldShiftHash( key );

        while( table[ index % 20 ] != key && table[ index % 20 ] == -5 ) {
            index++;
            // cout << "test";
        }
        cout << "from key " << key << " id is " << index % 20 << endl;
    }
};
int main() {
    HashTable ht(20);

    char command;

    while ( command != 'E' ) {

        cin >> command;

        if ( command == 'A' ) {
            long key;
            cin >> key;
            ht.insert( key );
        }

        if ( command == 'R' ) {
            long key;
            cin >> key;
            ht.remove( key );
        }

        if ( command == 'P' ) {
            ht.display();
        }
    }

    return 0;
}