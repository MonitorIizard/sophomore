#include<iostream>
using namespace std;

typedef struct Node {
  int id;
  Node* next;
  Node* prev;
} Node;

Node* head = NULL;
Node* tail = head;

void printAllElement();

bool checkDuplicate( int idToCheck ) {
  Node* curr = head;
  
  while( curr != NULL ) {
    if ( curr -> id == idToCheck ) return true;
    curr = curr -> next;
  }

  return false;
}

void insertBefore( int insertId, int position ) {
  if( checkDuplicate( insertId ) ) return;

  Node* newNode = new Node();
  newNode -> id = insertId;
  newNode -> next = NULL;
  newNode -> prev = NULL;

  if( head == NULL ) {
    head = newNode;
    tail = head;
    printAllElement();
    // cout << "case1"<< endl;
    return;
  }

  Node* curr = head;

  if ( curr -> id == position ) {
      newNode -> next = curr;
      curr -> prev = newNode;
      head = newNode;
      printAllElement();
      // cout << "case2"<< endl;
      return;
    }

  while ( curr -> next != NULL ) {
    if( curr -> next -> id == position ) {
      newNode -> next = curr -> next;
      newNode -> prev = curr;
      curr -> next -> prev = newNode;
      curr -> next = newNode;
      printAllElement();
      // cout << "case3"<< endl;
      return;
    }

    curr = curr -> next;
  }
  
  // if there is no Id insert last
  curr -> next = newNode;
  newNode -> prev = curr;
  tail = newNode;
  printAllElement();
  // cout << "case4"<< endl;
}

void insertAfter( int insertId, int position ) {
  if ( checkDuplicate( insertId ) ) return;

  Node* newNode = new Node();
  newNode -> id = insertId;
  newNode -> next = NULL;
  newNode -> prev = NULL;

  if ( head == NULL ) {
    head = newNode;
    printAllElement();
    return;
  }

  Node* curr = head;

  while( curr -> next != NULL ) {

    if ( curr -> id == position ) {
      newNode -> next = curr -> next;
      newNode -> prev = curr;
      curr -> next -> prev = newNode;
      curr -> next = newNode;

      printAllElement();
      return;
    }

    curr = curr -> next;
  }

  curr -> next = newNode;
  newNode -> prev = curr;
  tail = newNode;
  printAllElement();
}

void deleteNode( int idToDelete ) {
  if ( head -> id == idToDelete &&
       head -> next == NULL ) return;
  
  Node* curr = head;
  Node* temp;

  if ( head -> id == idToDelete ) {
    temp = head;

    head = head -> next;
    head -> prev = NULL;

    Node* temp = curr;
    delete temp;

    printAllElement();

    return;
  }

  if ( tail -> id == idToDelete ) {
    temp = tail;

    tail = tail -> prev;
    tail -> next = NULL;

    delete temp;
    
    printAllElement();
    
    return;
  }

  while ( curr -> next != NULL ) {
    temp = curr;


    if ( curr -> id == idToDelete ) {
      curr -> next -> prev = curr -> prev;
      curr -> prev -> next = curr -> next;

      temp = curr;
      delete temp;

      printAllElement();

      return;
    }

    curr = curr -> next;
  }
      
}

void printAllElement() {
  Node* curr = head;

  while( curr != NULL ) {
    cout << curr -> id << " ";
    curr = curr -> next;
  }

  cout << endl;
}

int main () {

  char command;

  int idToInsert;
  int position;
  int idToDelete;

  // insertBefore( 1, 0 );
  // insertBefore( 2, 1 );

  while ( command != 'E' ) {
    cin >> command;

    if ( command == 'I' ) {
      cin >> idToInsert;
      cin >> position;

      insertBefore( idToInsert, position );
    }

    if ( command == 'A' ) {
      cin >> idToInsert;
      cin >> position;

      insertAfter( idToInsert, position );
    }

    if ( command == 'D' ) {
      cin >> idToDelete;

      deleteNode( idToDelete );
    }
  }

  return 0;
}