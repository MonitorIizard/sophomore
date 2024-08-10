#include <iostream>
using namespace std;

int main () {
  int n = 17;
  int m = 9;

  int round = 0;

  while ( m != n ) {
    if ( m > n ) {
      m = m - n;
    } else {
      n = n - m;
    }

    round++;
  }


  cout << round;
}