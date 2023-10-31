// create christmas tree in array and display 
// we need width and height of the tree and height of leaves

#include <iostream>
#include <cmath>
using namespace std;

#define LEAVE '*'
#define TRUNK '|'
#define mt ' '

int main() {
    int trunkHeight;
    int trunkWidth;
    cin >> trunkWidth;
    cin >> trunkHeight;

    int height;
    cin >> height;

    int max = ( height * 2 ) - 1;
    int middle = ( max / 2 ) + 1;; 
    int left = middle;
    int right = middle;

    char answer[ height + trunkHeight ][max];

    cout << middle;

    for ( int row = 1 ; row <= height ; row++ ) {
        for ( int column = 1; column <= max; column++ ) {
            if ( column >= left && column <= right ) { 
                answer[ row - 1][ column - 1 ] = LEAVE;
            } else {
                answer[ row - 1 ][ column - 1 ] = mt;
            }
        }
        left -= 1;
        right += 1;

    }

    if ( trunkWidth % 2 == 0 ) {
        left = middle - ( trunkWidth / 2 );
        right = middle + ( trunkWidth / 2 ) - 1;
    } else { 
        left = middle - floor( trunkWidth / 2 );
        right = floor( trunkWidth / 2 ) + middle;
    }

    for ( int i = 1; i <= trunkHeight; i++ ) {
        for ( int j = 1; j <= max; j++ ) {
            if ( j >= left && j <= right ) {
                answer[ height + i - 1 ][ j - 1 ] = TRUNK;
            } else {
                answer[ height + i - 1 ][ j - 1 ] = mt;
            }
        }

        cout << endl;
    }

    for ( int row = 1 ; row <= height + trunkHeight ; row++ ) {
        for ( int column = 1; column <= max; column++ ) {
            cout << answer[ row - 1 ][ column - 1 ];
        }
        cout << endl;
    }
}