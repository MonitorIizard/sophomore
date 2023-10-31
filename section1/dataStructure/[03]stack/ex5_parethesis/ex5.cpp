#include <iostream>
using namespace std;

class Node {
public:
  char bracket;
  Node* next;
  Node* prev;

  Node( char bracket ) : bracket( bracket ), next( NULL ), prev( NULL ) {};
};

class Stack {
private:
  Node* head;
  Node* tail;
  
  int size;

public:
  Stack() {
    head = new Node( '\0' );
    tail = new Node( '\0' );

    head -> next = tail;
    tail -> prev = head;

    size = 0;
  }

  void insert( char bracket ) {
    Node* newNode = new Node( bracket );
    Node* curr = head;

    while( curr -> next != tail ) {
      curr = curr -> next;
    }

    newNode -> next = curr -> next;
    newNode -> prev = curr;
    curr -> next -> prev = newNode;
    curr -> next = newNode;

    size++;
  }

  void pop() {
    Node* curr = tail -> prev;

    if( curr == head ) {
      return;
    }

    curr -> next -> prev = curr -> prev;
    curr -> prev -> next = curr -> next;

    size--;
    delete curr;
  }

  char peek() {
    if ( tail -> prev == head ) {
      return '-';
    } 

    return tail -> prev -> bracket;
  }

  void displayAll() {
    Node* curr = head -> next;

    if ( curr == tail ) {
      cout << "-";
    }

    while( curr  != tail ) {
      cout << curr -> bracket << "->";
      curr = curr -> next;
    }

    cout << endl;
  }

  int getSize() {
    // cout << "size is " << size << endl;
    return size;
  }
};

class Data {
public:
  char openBracket;
  char closeBracket;

  Data( char open, char close ) : openBracket( open ), closeBracket( close ) {}
};

class Solution {
private: 
  Stack stack1;
public:
  bool isValid( string s ) {
    int lengthOfs = end( s ) - begin( s );

    Data* arrays[ 3 ];
    arrays[ 0 ] = new Data( '(', ')' );
    arrays[ 1 ] = new Data( '{', '}' );
    arrays[ 2 ] = new Data( '[', ']' );
    
    int i = 0;
    while( i < lengthOfs ) {
      unsigned int index = hashFunction( s[i] );
      if( s[i] == arrays[ index ] -> openBracket ) {
        stack1.insert( s[i] );
      }

      if( s[i] == arrays[ index ] -> closeBracket ) {
        // cout << "this case";
        if ( stack1.peek() == arrays[ index ] -> openBracket ) stack1.pop();
        else { return false; }
      }

      i++;
    }

    // stack1.displayAll();
    if ( stack1.getSize() == 0 ) return true;
    return false;
  }

  unsigned int hashFunction( char bracket ) {
    if ( bracket == '(' || bracket == ')' ) return 0;
    if ( bracket == '{' || bracket == '}' ) return 1;
    if ( bracket == '[' || bracket == ']' ) return 2;

    return -1;
  }
};

int main () {
  Solution solution1;
  cout << solution1.isValid( "(())" );

  Stack stack1;
  // stack1.insert( '(' );
  // stack1.pop();
  // stack1.insert( '(' );
  // stack1.displayAll();
  return 0;
}