#include <iostream>
using namespace std;

int N = 10;
int arrays[10];
int front = -1;
int rear = -1;

bool isEmpty() {
    if ( front == -1 && rear == -1 ) {
        cout << "array is empty" << endl;
        return true;
    } else {
        return false;
    }
}

void enqueue ( int data ) {

    if ( front == rear + 1 % N) {
        cout << "array is full" << endl;
        return;
    }

    if ( isEmpty() ) {
        front = 0;
        rear = 0;
        
    } else {
        rear = rear + 1 % N;

    }

    arrays[rear] = data;
}

void dequeue () {
    if ( isEmpty() ) {
        return;
    }

    if ( front == rear ) {
        front = -1;
        rear = -1;
    } 

    front = front + 1 % N;

}

void displayArray() {
    int i = front;

    while (i < N) {
        cout << arrays[i] << "->";
        i++;
    }
}

int main () {

    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    dequeue();
    displayArray();
    return 0; 
}