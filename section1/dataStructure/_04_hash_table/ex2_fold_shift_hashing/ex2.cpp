#include <iostream>
#include <sstream> 
using namespace std;

#define ARRAYSIZE 20
#define STUDENT_ID_SIZE 14

unsigned long hashFunction( char* key ) {

  key += 1;
  int i = 0;
  int sum = 0;
  string s;

  while( *( key ) != '\0' ) {

    if ( i == 4 ) {
      sum += stoi(s);
      i = 0;
      s.clear();
      
    } else {
      s += *( key );
      key += 1;
      i++;
    }
  }

  // cout << s << endl;
  sum += stoi(s);
  return ( sum ) % ARRAYSIZE;
}

int main () {
  char key[STUDENT_ID_SIZE] = "6504062620159";
  // unsigned long index = hash( key );
  cout << hashFunction( key ) << endl;
  cout << 11461 % 20 << endl;
  cout << 5040 + 6262 + 159;
}
