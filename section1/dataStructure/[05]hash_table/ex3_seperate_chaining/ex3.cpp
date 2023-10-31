#include <iostream>
using namespace std;

#define ARRAY_SIZE 17

class Node {
public:
  int key;
  string value;
  Node* next;

  Node( int key, string value) : value( value ), key( key ), next( NULL ) {};
};

class LinkList {
private:
  Node* head = NULL;
  
public:
  void insert( int key, string value ) {
    Node* curr = head;
    Node* newNode = new Node( key, value );

    if ( head == NULL ) {
      head = newNode;
      return;
    }

    while( curr -> next != NULL ) {
      curr = curr -> next;
    }

    curr -> next = newNode;
  }

  void display() {
    Node* curr = head;

    if ( curr == NULL ) {
      cout << "(-1,-)";
      cout << endl;
      return;
    } 
    
    while( curr != NULL ) {
      cout << "(" << curr -> key << "," << curr -> value << ") ";
      curr = curr -> next;
    }
    
    cout << endl;
  }

  void seek( int key ) {
    Node* curr = head;

    while( curr != NULL ) {
      if( curr -> key == key ) {
        cout << curr -> value << endl;
        return;
      }

      curr = curr -> next;
    }

    cout << "-" << endl;
  }
};

class hashTable {
public:
  LinkList arrays[ARRAY_SIZE];

  unsigned long hashFunction( int key ) {
    return key % ARRAY_SIZE;
  }

  void display() {
    int i = 0;
    while ( i < ARRAY_SIZE ) {
      arrays[ i ].display();
      i++;
    }
  }

  void insert( int key, string value ) {
    int idxToIns = hashFunction( key );
    arrays[ idxToIns ].insert( key, value );
  }

  void find( int key ) {
    int idxToFind = hashFunction( key );
    arrays[ idxToFind ].seek( key );
  }

};

int main() {
  hashTable hashTable1;

  char command;

  while( command != 'e' ) {
    cin >> command;

    if ( command == 'a' ) {
      int key;
      string value;

      cin >> key;
      cin >> value;

      hashTable1.insert( key, value );
    }

    if ( command == 's' ) {
      int key;
      cin >> key;

      hashTable1.find( key );
    }
    
    if ( command == 'p' ) {
      hashTable1.display();
    }
  }

  return 0;
}