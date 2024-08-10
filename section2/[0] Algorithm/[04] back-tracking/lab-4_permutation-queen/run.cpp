#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void permute(int data[], int start, int end) {
  if ( start == end ) {
    for ( int column = 1; column <= end; column++ ) {
      int refRow = data[column];
      int referencePoint[] = {column, refRow};
      int x1 = referencePoint[0];
      int y1 = referencePoint[1];

      for ( int i = column + 1; i <= end; i++ ) {
        int toCompareRow = data[i];
        int toComparePoint[] = {i, toCompareRow};
        int x2 = toComparePoint[0];
        int y2 = toComparePoint[1];

        if ( abs(x1 - x2) == abs(y1 - y2) ) {
          return;
        }

        if ( y1 == y2 ) {
          return;
        }
      }
    }

    for ( int i = 1; i <= end; i++ ) {
      printf( "%d", data[i] );
    } 
    cout << endl;
    return;
  }

  for ( int i = start; i <= end; i++ ) {
    swap( data[start], data[i] );
    permute( data, start + 1, end );
    swap( data[start], data[i] );
  }
}

int main() {
  int numberOfElement = 4;
  int answer[numberOfElement + 1];
  int data[] = { -1, 1, 2, 3, 4, 5 };
  int startIndex = 1;

  permute( data, startIndex, numberOfElement );
}