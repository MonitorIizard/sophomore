#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    Node *prev;
    Node *next;
} Node;

void pop ( Node **head, Node **trail ) {
    if ( *head != NULL ) {
        Node *curr = *trail;
        if ( *head == *trail ) {
            *head = NULL;
        }

        if ( ( *trail ) -> prev != NULL ) {
            *trail = ( *trail ) -> prev;
            ( *trail ) -> next = NULL;
        }
        delete curr;
    }
}

void add( char data, Node **head, Node **trail ) {
    Node *temp = new Node;
    temp  -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;

    if ( *head == NULL ) {
        *head = temp;
        *trail = *head;
    } else {
        ( *trail ) -> next = temp;
        temp -> prev = *trail;
        *trail = temp;
    }
}

void displayAll( Node **head ) {
    for ( Node *curr = *head; curr != NULL ; curr = curr -> next ) {
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
    
    Node *headOfFiltered = NULL;
    Node *trailOfFiltered = headOfFiltered;

    int i = 0;
    int k = 0;
    while ( *( messege + i) != '\0' ) {

        char currentCharacter = *( messege + i );
        
        if ( currentCharacter == '(' ) {
            add( currentCharacter, &headOfFiltered, &trailOfFiltered );
            // cout << "add " << currentCharacter << " " << "now"; 
            // displayAll( &headOfFiltered );
            k++;
        }

        if ( currentCharacter == ')' ) {
            pop( &headOfFiltered, &trailOfFiltered );
            // cout << "pop " << currentCharacter << " " << "now";
            // displayAll( &headOfFiltered );
            k--;
        }

        if ( k < 0 ) {
            cout << "Error";
            return 0;
        }

        i++;
    }

    if ( k != 0 ) {
        cout << "Error";
    } else {
        cout << "Pass";
    }
    // displayAll( &headOfFiltered );

    return 0;
}