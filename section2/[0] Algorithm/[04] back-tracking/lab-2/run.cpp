#include <stdio.h>

void printSolution( int x[], int n ) {
  for ( int i = 1; i <= n; i++ ) {
    printf("%d", x[i]);
  }
  printf("\n");
}

void subset( int x[], int l, int r ) {
  if ( l == r ) {
    printSolution( x, r );
  }
}