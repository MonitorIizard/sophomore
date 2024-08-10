#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* head = NULL;
Node* trail = head;

void enqueue( int data ) {
    Node* newNode = new Node();
    newNode -> data = data;
    // newNode -> prev = NULL;
    newNode -> next = NULL;

    if ( head == NULL ) {
        head = newNode;
        trail = head;
    } else {
        trail -> next = newNode;
        // newNode -> prev = trail;
        trail = newNode;
    }
}

void dequeue( ) {
    Node *temp = head;
    head = head -> next;
    cout << temp -> data << endl;
    delete temp;
}

void printAll( ) {
    Node *curr = head;
    while( curr != NULL ) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

int findLength( ) {
    Node* curr = head;
    int i = 0;
    while ( curr != NULL ) {
        i++;
        curr = curr -> next;
    }
    return i;
}

void printHeadAndTrail( ) {
    if ( head == NULL & trail == NULL ) {
        return;
    }

    cout << head -> data << " " << trail -> data << endl;
}

int main() {
    char operation;
    while( true ) {
        cin >> operation;

        if ( operation == 'e' ) {
            int data;
            cin >> data;
            enqueue( data );
        }

        if ( operation == 'd' ) {
            dequeue( );
        }

        if ( operation == 'p' ) {
            printAll( );
        }

        if ( operation == 'n' ) {
            cout << findLength( ) << endl;
        }

        if ( operation == 's' ) {
            printHeadAndTrail( );
        }

        if ( operation == 'x' ) {
            break;
        }

    }
    return 0;
}