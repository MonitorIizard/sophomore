#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

bool isEmpty() {
    if ( front == NULL && rear == NULL ) {
        return true;
    } else {
        return false;
    }
}

void enqueue( int value ) {
    Node *ptr = new Node();
    ptr -> data = value;
    ptr -> next = NULL;
    
    if ( front == NULL ) {
        front = ptr;
        rear = ptr;

    } else {
        rear -> next = ptr;
        rear = ptr;
    }
}

void dequeue () {
    if ( isEmpty() ) {
        cout << "Queue is Empty";

    } else {
        if ( front == rear ) {
            free( front );
            front = NULL;
            rear = NULL;

        } else {
            Node *ptr = front;
            front = front -> next;
            free( ptr );

        }
    }
}

void showFront () {
    if ( isEmpty() ) {
        cout << "Queue Is Empty";

    } else {
        cout << front -> data; 

    }
}

void displayQueue () {
    if ( isEmpty() ) {
        cout << "Queue Is Empty";

    } else {
        Node *ptr = front;

        while ( ptr != NULL ) {
            cout << ptr -> data << "->";
            ptr = ptr -> next;

        }   
    }
}

int main () {

    enqueue(5);
    enqueue(2);
    enqueue(7);
    dequeue();
    showFront();
    displayQueue();

    return 0;
}