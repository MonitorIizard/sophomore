#include <iostream>
using namespace std;

#define ARRAY_SIZE_MAIN 17
#define ARRAY_SIZE_SECONDARY 11

class Data {
public:
  int key;
  string value;

  Data( int key, string value ) : key( key ), value( value ) {}
};

class HashTable {
private:
  Data* arrays[ ARRAY_SIZE_MAIN ];

public:

  HashTable() {
    int i = 0;
    while( i < ARRAY_SIZE_MAIN ) {
      arrays[i] = NULL;
      i++;
    }
  }

  unsigned int hashFunction1( int key ) {
    return key % ARRAY_SIZE_MAIN;
  }

  unsigned int hashFunction2( int key ) {
    return key % ARRAY_SIZE_SECONDARY;
  }

  unsigned int probingFunction( int key, int round ) {
    return round * ( ARRAY_SIZE_SECONDARY - hashFunction2( key ));
  }

  void insert( int key, string value ) {
    int index = hashFunction1( key );
    int original = index;
    int round = 0;

    Data* newData = new Data( key, value );

    while( arrays[ index ] != NULL ) {
      index = (hashFunction1( key ) + probingFunction( key, round )) % ARRAY_SIZE_MAIN;
      round++;

      if ( round == ARRAY_SIZE_MAIN ) {
        return;
      }
    }

    arrays[ index ] = newData;
  }

  void seek( int key ) {
    int index = hashFunction1( key );
    int originalIndex = index;

    // if ( arrays[ index ] == NULL ) {
    //   cout << '-' << endl;
    //   return;
    // }

    // cout << index << endl;
    

    //error on arrays[index] -> key because it null
    int round = 0;
    while( arrays[ index ] != NULL ) {
      if (  arrays[ index ] -> key == key ) {
        cout << arrays[ index ] -> value << endl;
         return;
      }

      index = (hashFunction1( key ) + probingFunction( key, round )) % ARRAY_SIZE_MAIN;
      round++;
    }

    if ( arrays[ index ] == NULL ) {
      cout << '-' << endl;
      return;
    }

  }

  void display() {
    int i = 0;


    while ( i < ARRAY_SIZE_MAIN ) {
      if ( arrays[ i ] == NULL ) {
        cout << "(-1,-)";
      } else { 
        cout << "(" << arrays[ i ] -> key << "," << arrays[ i ] -> value << ") ";
      }
      i++;
      cout << endl;

    }
  }
};

int main () { 
  HashTable hashTable1;

  char command;

  while( command != 'e' ) {
    cin >> command;

    if ( command == 'a' ) {
      int key;
      string value;

      cin >> key;
      cin >> value;

      hashTable1.insert( key, value );
    }

    if ( command == 's' ) {
      int key;
      cin >> key;

      hashTable1.seek( key );
    }
    
    if ( command == 'p' ) {
      hashTable1.display();
    }
  }

  return 0;
}

// a 1415 xxxt
// a 1712 yyyt
// a 2041 yout

// a 2158 onit
// a 3619 eggt
// a 1896 godt

// a 3010 nomt
// a 2589 xd
// a 7741 rae
// a 3654 eeec
