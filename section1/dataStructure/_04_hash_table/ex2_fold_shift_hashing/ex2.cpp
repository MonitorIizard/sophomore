#include <iostream>
#include <sstream> 
using namespace std;

#define ARRAYSIZE 20
#define STUDENT_ID_SIZE 14

class Node {
public : 
  string stdId;
  Node* next;
  
  Node( string value ) : stdId ( value ), next( nullptr ) {} 
};

class LinkedList  {
public : 
  Node* head;
  
  LinkedList() : head( nullptr ) {}
  
  void insert( string numberId ) {
    Node* newNode = new Node( numberId );

    if ( head == nullptr ) {
      head = newNode;

    } else { 
      Node* current = head;

      while( current -> next != nullptr ) {
        current = current -> next;
      }
      current -> next = newNode;

    }
  } 

  void display() {

    if ( head == nullptr ) {
      cout << "-1" << endl;
      return;
    }

    Node* current = head;

    while( current != nullptr ) {
      cout << current -> stdId << "->";
      current = current -> next;
    }

    cout << endl;
  }

  void findNode( string studentIdToFind ) {
      Node* curr = head;
      while( curr != nullptr ) {
        if ( curr -> stdId == studentIdToFind ) {
            cout << "id : " << curr -> stdId << endl;
        }
        curr = curr -> next;
      }
  }

  void deleteNode( string numberIdToRemove ) {
    Node* temp;

    if ( head -> stdId == numberIdToRemove ) {
      temp = head;
      head = head -> next;
      delete temp;
      return;
    }

    Node* curr = head;
    temp = curr;

    curr = curr -> next;

    while ( curr -> next != nullptr ) {

      if ( curr -> stdId == numberIdToRemove ) {
        temp -> next = curr -> next;
        delete curr;
        return;
      }

      curr = curr -> next;
    }
    
  }
};

unsigned long hashFunction( char* key ) {

    key += 1;
    int i = 0;
    int sum = 0;
    string s;

    while( *key != '\0' ) {

      if ( i == 4 ) {
        sum += stoi(s);
        i = 0;
        s.clear();
        
      } else {
        s += *( key );
        key += 1;
        i++;
      }
    }
    sum += stoi(s);
    return ( sum ) % ARRAYSIZE;
}


int main () {
  char key[STUDENT_ID_SIZE];
  LinkedList array[ARRAYSIZE];

  char command;

  while ( command != 'E' ) {
    cin >> command;

    if ( command == 'A' ) {
      cin >> key;
      int index = hashFunction( key );
      array[ index ].insert( key );
    }

    if ( command == 'P' ) {
      int i = 0;
      while( i < 20 ) {
        array[ i ].display();
        i++;
      }
    }

    if ( command == 'D' ) {
      cin >> key;
      int index = hashFunction( key );
      array[ index ].deleteNode( key );
    }

    if ( command == 'F' ) {
      cin >> key;
      int index = hashFunction( key );
      array[ index ].findNode( key );
    }

    cout << endl;
  }

}