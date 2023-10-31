#include <iostream>
using namespace std;


typedef struct Node {
    int data;
    Node *next;
} Node;

void displayAll( Node **head );

void insertFirst( int data, Node **head ) {
    Node *new_node = new Node();
    new_node -> next = *head;
    new_node -> data = data;
    *head = new_node;
}

void insertLast( int data, Node **head ) {

    Node *new_node = new Node();
    new_node -> data = data;
    new_node -> next = NULL;

    if ( *head == NULL ) {
        *head = new_node;
        return;
    }

    Node *last = *head;
    while ( last -> next != NULL ) {
        last = last -> next;
    }

    last -> next = new_node;

}

void insertAfter( int data, Node **curr ) {
    Node *new_node = new Node();

    displayAll( &(*curr) );
    new_node -> next = ( *curr ) -> next;
    new_node -> data = data;
    ( *curr ) -> next = new_node;

}

int checkLength( Node **head ) {
    Node *curr = *head;
    int i = 0;
    while ( curr != NULL ) {
        curr = curr -> next;
        i++;
    } 
    return i;
}

void insertAt( int data, int index, Node **head ) {
    if ( checkLength(&( *head )) <= index ) {
        insertLast( data, &(*head) );
        return;
    }

    if ( index == 0 ) {
        insertFirst( data, &(*head) );
        return;
    }

    Node *curr = *head;
    int i = 0;
    while( i < index - 1 ) {
        curr = curr -> next;
        i++;
    }

    insertAfter( data, &curr ); 
}

void displayAll( Node **head ) {
    Node *curr = *head;
    while ( curr != NULL ) {
        cout << curr -> data << "->";
        curr = curr -> next;
    }
}

int main() {
    Node *root = NULL;
    char operation;

    while ( true ) {

        cin >> operation;

        if ( operation == 'A' ) {
            int data;
            int index;
            cout << "insert index and data : ";
            cin >> index;
            cin >> data;

            insertAt( data, index , &root );
            
        }

        if ( operation == 'X' ) {
            break;
        }

    }

    //cout << checkLength( &root );

    displayAll( &root );
    return 0;
}