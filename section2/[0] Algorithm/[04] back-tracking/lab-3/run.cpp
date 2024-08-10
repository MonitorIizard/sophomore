#include <stdio.h>

void printSolution( int x[], int n ) {
  for ( int i = 1; i <= n; i++ ) {
    printf("%d", x[i]);
  }
  printf("\n");
}

void subset( int x[], int left, int right ) {
  if ( left == right ) {
    printSolution( x, right );
  } else {
    x[left + 1] = 1;
    subset(x, left + 1, right);
    x[left + 1] = 0;
    subset(x, left + 1, right);
  }
}

int main () {
  int n = 3;
  int x[n + 1];

  subset( x, 0, n );
  return 0;
}