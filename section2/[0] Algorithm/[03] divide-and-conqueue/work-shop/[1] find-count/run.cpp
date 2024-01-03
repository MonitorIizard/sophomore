#include <iostream>
using namespace std;

int count(int arr[], int l, int r, int target ) {
  if ( l < r ) {
    int mid = (l) + (r-l) / 2;
    int leftC = 0;
    int rightC = 0;

    if (target <= arr[mid]) {
      leftC = count(arr, l, mid, target);
    }

    if (target >= arr[mid]) {
      rightC = count(arr, mid+1, r, target);
    }

    return leftC + rightC;
  }

  if ( l == r && arr[l] == target ) {
    return 1;
  }

  return 0;
}

void merge( int arr[], int l, int m, int r) {
  
  int size1, size2;
  size1 = m - l + 1;
  size2 = r - m;

  int L[size1];
  int R[size2];

  // copy elements from left to m from arr[] to L[].
  int i = 0;
  while ( i < size1 ) {
    L[i] = arr[i + l];
    i++;
  } 

// copy elements from m+1 to right from arr[] to R[].
  int j = 0;
  while ( j < size2 ) {
    R[j] = arr[m + j + 1];
    j++;
  }

  i = 0;
  j = 0;
  int k = l;

  while ( i < size1 && j < size2 ) {
    if ( L[i] <= R[j] ) {
      arr[k++] = L[i];
      i++;
    } else {
      arr[k++] = R[j];
      j++;
    }
  }

  while ( i < size1 ) {
    arr[k++] = L[i];
    i++;
  }

  while ( j < size2 ) {
    arr[k++] = R[j];
    j++;
  }
}

void mergeSort( int arr[], int l, int r ) {
  if ( l < r ) {
    int m = (l + r) / 2;

    mergeSort( arr, l, m );
    mergeSort( arr, m + 1, r);
    
    merge( arr, l, m, r);
  }
}

int main() {
  int size;
  cin >> size;

  int target;
  cin >> target;

  int arr[size];

  for ( int i = 0; i < size; i++ ) {
    cin >> arr[i];
  }

  mergeSort( arr, 0, sizeof(arr)/sizeof(int) - 1);

  int c = count( arr, 0, sizeof(arr)/sizeof(int) - 1, target);

  if ( c == 0 ) {
    cout <<  -1;
  } else {
    cout << c;
  }

  return 0;
}