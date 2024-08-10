#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
    Node *previous;
} Node;

Node *head = NULL;
Node *trail = head;

void pop ( ) {
    if ( head != NULL ) {
        Node *curr = trail;
        if ( head == trail ) {
            cout << trail -> data << endl;
            head = NULL;
        }

        if ( trail -> previous != NULL ) {
            cout << trail -> data << endl;
            trail = trail -> previous;
            trail -> next = NULL;
        }
        delete curr;
    }
}

void add( int data ) {
    Node *temp = new Node;
    temp  -> data = data;
    temp -> next = NULL;
    temp -> previous = NULL;

    if ( head == NULL ) {
        head = temp;
        trail = head;
    } else {
        trail -> next = temp;
        temp -> previous = trail;
        trail = temp;
    }
}

void peek() {
    cout << trail -> data << endl;
}

void displayAll() {
    for ( Node *curr = head; curr != NULL ; curr = curr -> next ) {
        if ( curr -> next == NULL ) {
            cout << curr -> data << " ";
        } else {
            cout << curr -> data << " ";
        }
    }

    cout << endl;
}

int findLength() {
    int length = 0;
    for ( Node *curr = head; curr != NULL; curr = curr -> next ) {
        length += 1;
    }
    return length;
}

int main () {

    while ( true ) {
        char operation;
        cin >> operation;

        if ( operation == 'U' ) {
            int data;
            cin >> data;
            add( data );
        }

        if ( operation == 'O' ) {
            pop( ); 
        }
        
        if ( operation == 'T' ) {
            peek( );
        }

        if ( operation == 'P' ) {
            displayAll( );
        }

        if ( operation == 'N' ) {
            cout << findLength( ) << endl;
        }

        if ( operation == 'X' ) {
            break;
        }
    }
    return 0;
}