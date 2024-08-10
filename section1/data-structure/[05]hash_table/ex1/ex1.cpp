#include <iostream>
using namespace std;

#define HASHSIZE 17

unsigned long hashFunction( int key ) {
  return key % HASHSIZE;
}

int main () {



  return 0;
}