#include <iostream>
#include <math.h>
using namespace std;

class Node {
public: 
  int data;
  Node* next;
  Node* prev;

  Node( int data ) : data( data ), next( NULL ), prev( NULL ) {};
};

class LinkedList {
private: 
  Node* head = NULL;
  Node* trail = NULL;
  Node* curr = head;

public:

  LinkedList() {
    head = new Node( 0 );
    trail = new Node( 0 );

    head -> next = trail;
    trail -> prev = head;
    curr = trail;
  }

  void insert( int data ) {
    Node* newNode = new Node( data );

    // if ( head == NULL ) {
    //   head = newNode;
    //   curr = newNode;
    //   return; //!
    // }

    // if ( head == curr ) {
    //   newNode -> next = curr;
    //   curr -> prev = newNode;
    //   curr = newNode;
    //   head = curr;
    //   return;
    // }

    Node* traverse = head;
    while ( traverse != curr ) {
      traverse = traverse -> next;
    }

    newNode -> next = curr;
    newNode -> prev = curr -> prev;
    curr -> prev -> next = newNode;
    curr -> prev = newNode;
    curr = newNode;

    //  newNode -> next = curr;
    // newNode -> prev = curr -> prev;
    // curr -> prev = newNode;
    // curr = newNode;
  }

  void checkCurr() {
    cout << "now curr is " << curr -> data << endl;
  }

  void move( int round ) {
    int i = 0;
    int mode;

    if ( round < 0 ) {
      mode = -1;
    } else {
      mode = 1;
    }

    Node* traverse = curr;
    while ( i * mode < abs( round ) ) {

      if ( round < 0 ) {
        if ( traverse -> prev == head ) {
          curr = traverse;
          return;
        }
        traverse = traverse -> prev;
      } else {
        if ( traverse == trail ) {
          curr = traverse;
          return;
        }
        traverse = traverse -> next;
      }

      i += mode;
    }

    curr = traverse;
  }

  void erase() {
    //!! forgot to join node
    Node* temp = curr;

    if ( curr == trail ) {
      return;
    }

    // //!! forgot head
    // if ( head == NULL || curr -> next == NULL ) {
    //   return;
    // }

    // if ( curr == head ) {
    //   curr = curr -> next;
    //   head = curr;
    //   delete temp;
    //   return;
    // }

    // if ( curr -> next == NULL ) {
    //   curr = curr ->;
    //   return;
    // }

    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    curr = curr -> next;
    
    delete temp;
  }

  void display() {
    Node* traverse = head -> next;
    while ( traverse != trail ) {
      cout << traverse -> data << endl;
      traverse = traverse -> next;
    }

    cout << endl;
  }
};

int main () {
  int round;
  cin >> round;

  int i = 0;
  char command;
  LinkedList LinkedList1;
  while ( i < round ) {
    cin >> command;

    if ( command == '0' ) {
      int data;
      cin >> data;
      
      LinkedList1.insert( data );
    }

    if ( command == '1' ) {
      int step;
      cin >> step;
      
      LinkedList1.move( step );
      // LinkedList1.checkCurr();
    }

    if ( command == '2' ) {
      LinkedList1.erase();
    }

    if ( command == '3' ) {
      LinkedList1.display();
    }

    i++;
  }

  LinkedList1.display();

  return 0;
}