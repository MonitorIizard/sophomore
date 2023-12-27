#include <iostream>
using namespace std;

void insertionSort( int arr[], int size ) {
  int data;
  cin >> data;
  arr[0] = data;
    
  for ( int i = 1; i < size; i++ ) {
    cin >> data;
    arr[i] = data;
    for ( int j = i; j > 0 && arr[j] < arr[j-1]; j-- ) {
      swap(arr[j], arr[j-1]);
    }
  }
}

void swap( int *x, int *y ) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int size;
  cin >> size;

  int arr[size];

  insertionSort( arr, size );

  int unique = 1;

  for ( int i = 1; i < size; i++ ) {
    if ( arr[i-1] != arr[i]) {
      unique++;
    }
  }
  
  cout << unique;
}