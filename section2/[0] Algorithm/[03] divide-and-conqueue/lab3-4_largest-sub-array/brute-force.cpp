#include <iostream>
using namespace std;

void findMaxInterval( int arr[], int l, int r, int *M ) {
  if ( l < r ) {  
    findMaxInterval( arr, l + 1, r, M);
    findMaxInterval( arr, l + 1, r - 1, M);
    findMaxInterval( arr, l, r - 1, M);

    int max = 0;
    for( int i = l; i < r; i++ ) {
      // cout << arr[i] << " ";
      max += arr[i];
    }
    
    if ( max > *M ) {
      *M = max;
    }
  }

}

int main() {
  int size = 0;
  cin >> size;
  int max = -200000;

  // int arr[size] = {2, -4, 1, 9, -6, 7, -3};
  int arr[size];

  for( int i = 0; i < size; i++ ) {
    cin >> arr[i];
  }

  findMaxInterval( arr, 0, size, &max);

  cout << max;
}