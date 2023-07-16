#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    Node *next;
    Node *previous;
} Node;

Node *head = NULL;
Node *trail = head;

void pop ( ) {
    if ( head != NULL ) {
        Node *curr = trail;
        if ( head == trail ) {
            cout << trail -> data;
            head = NULL;
        }

        if ( trail -> previous != NULL ) {
            cout << trail -> data;
            trail = trail -> previous;
            trail -> next = NULL;
        }
        delete curr;
    }
}

void add( char data ) {
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

void displayAll() {
    for ( Node *curr = trail; curr != NULL ; curr = curr -> previous ) {
        if ( curr -> next == NULL ) {
            cout << curr -> data << " ";
        } else {
            cout << curr -> data << " ";
        }
    }

    cout << endl;
}

int main () {
    char messege[ 100 ];
    cin >> messege;

    int i = 0;
    while ( *( messege + i ) != '\0' ) {
        char currrentCharacter = *( messege + i );
        add( currrentCharacter );
        i++;
    }

    while ( i >= 0 ) {
        char currrentCharacter = *( messege + i );
        pop( );
        i--;
    }

    return 0;
}