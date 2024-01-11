#include <iostream>
using namespace std;

int findMax(int a, int b) {
  if ( a > b ) {
    return a;
  }
  return b;
}

int findMaxBetween( int arr[], int l, int m, int r ) {
  int leftSum = -60000000;
  int sum = 0;
  for ( int i = m; i >= l; i-- ) {
    sum += arr[i];
    if ( sum > leftSum ) {
      leftSum = sum;
    }
  }

  int rightSum = -60000000;
  sum = 0;
  for ( int i = m; i <= r; i++ ) {
    sum += arr[i];
    if( sum > rightSum ) {
      rightSum = sum;
    }
  }
  return findMax( findMax(leftSum + rightSum - arr[m], rightSum) , leftSum );
}

int findMaxInterval( int arr[], int l, int r) {

  if ( l == r ) {
    return arr[l];
  }

  if ( l < r ) {  
    int mid = l + (r-l) / 2;
    return findMax(
      findMax(
        findMaxInterval( arr, l, mid - 1),
        findMaxInterval( arr, mid + 1, r)
      ),
      findMaxBetween(arr, l, mid, r)
    );
  }

  return -200000;

}

int main() {
  int size = 0;
  cin >> size;
  // int max = -200000;

  // int arr[size] = {2, -4, 1, 9, -6, 7, -3};
  int arr[size];

  for( int i = 0; i < size; i++ ) {
    cin >> arr[i];
  }

  int i = 0;

  cout << findMaxInterval( arr, 0, size - 1);

  // cout << max;
}
