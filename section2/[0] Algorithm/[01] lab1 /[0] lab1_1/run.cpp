#include <iostream>
using namespace std;

int main() {
  int capacity;
  cin >> capacity;
  
  int k;
  cin >> k;

  int arr[capacity];

  for ( int i = 0; i < capacity; i++ ) {
    int data;
    cin >> data;
    arr[i] = data;
  }

  for ( int i = 0; i < capacity; i++ ) {
    for ( int j = i; j < capacity; j++ ) {
      if ( arr[i] + arr[j] == k && i != j ) {
        cout << i << " " << j;
        return 0;
      }
    }
  }

  cout << "-1";

  return 0;
}