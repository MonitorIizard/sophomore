#include <iostream>
#include <string>
using namespace std;

long long int findFactorial(int number, int l, int r, int *count,long long int table[] ) {
  if ( l < r ) {
    *count += 1;
    int mid = l + (r - l) / 2;

    string key0 = to_string(abs(r - l + 1));
    string key1 = to_string(abs(mid - l + 1));
    string key2 = to_string(abs(r - mid));

    if (  table[stoi(key1)] == 0 ) {
      table[stoi(key1)] = findFactorial(number, l, mid, count, table);
    }

    if ( table[stoi(key2)] == 0 ) {
      // cout << "2 worked" << endl;
      table[stoi(key2)] = findFactorial( number, mid + 1, r , count, table);
    }

    if ( table[stoi(key0)] == 0 ) {
      table[stoi(key0)] =  table[stoi(key1)] * table[stoi(key2)];
    }
      
    // cout << table[stoi(key0)];

    return table[stoi(key0)];
  }

  return 1;
}

int main() {
  int count = 0;
  int number = 0;
  cin >> number;

  int size = 0;
  cin >> size;

  long long int hashTable[size + 1];

  hashTable[0] = 1;
  hashTable[1] = number;

  for ( int i = 2; i <= size; i++ ) {
    hashTable[i] = 0;
  }

  cout << findFactorial( number, 0 , size - 1 , &count, hashTable) << " " << count;
  // cout << " " << endl;
  return 0;
}