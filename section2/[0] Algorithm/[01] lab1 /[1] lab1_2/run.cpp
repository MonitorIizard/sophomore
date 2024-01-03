#include <iostream>
using namespace std;

int main() {
  int capacity;
  cin >> capacity;
  
  int arr[capacity];

  for ( int i = 0; i < capacity; i++ ) {
    int data;
    cin >> data;
    arr[i] = data;
  }

  int max = arr[0];
  for ( int i = 0; i < capacity; i++ ) {

    for ( int j = i + 1; j < capacity; j++ ) {
      int sum = 0;

       for ( int k = i; k <= j; k++ ) {
        sum += arr[k];
        if ( sum > max ) {
          max = sum;
        }
       }
    }
  }

  cout << max;

  return 0;
}