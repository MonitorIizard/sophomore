#include <iostream>
using namespace std;

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
  int size = 5;
  cin >> size;

  int arr[size];

  int k ;
  cin >> k;

  int data;

  for ( int i = 0; i < size; i++ ) {
    cin >> data;
    arr[i] = data;
  }

  mergeSort( arr, 0, size - 1);

  int ans1 = 0;
  int ans2 = 0;
  int min = arr[size - 1] - arr[0];

  // run though array
  for ( int i = 0; i < size; i++ ) {
    int toFind = k - arr[i];

    int left = 0;
    int right = size - 1;

    while (left <= right ) {
      int middle = (right + left) / 2;
      
      if ( arr[middle] > toFind ) {
        right = middle - 1;
      }

      if ( arr[middle] < toFind ) {
        left = middle + 1;
      }

      if ( arr[middle] == toFind ) {

        // cout << middle << " " << i << endl;

        if ( abs(toFind - arr[i]) <= min && middle != i ) {
          ans1 = arr[i];
          ans2 = arr[middle];
          min = abs(toFind - arr[i]);
        }

        break;
      }
    }
  }

  // int ansIndex1 = 0;
  // int ansIndex2 = 0;
  // int var1 = 0;
  // int var2 = size -1 ;

  // for ( int i = 0; i < size; i++ ) {
  //   if ( var1 == var2 ) {
  //     break; 
  //     }

  //   if ( arr[var1] + arr[var2] > k ) {
  //     var2--;
  //   } else if ( arr[var1] + arr[var2] < k) {
  //     var1++;
  //   } else if ( arr[var1] + arr[var2] == k ) {
  //     ansIndex1 = var1;
  //     ansIndex2 = var2;
  //     var1++;
  //   }
  // }

  if ( ans1 > ans2 ) {
    cout << ans2 << " " << ans1;
  } else {
    cout << ans1 << " " << ans2;
  }

  // cout << ans1 << " " << ans2 << endl;
  // cout << ansIndex1 << " " << ansIndex2 << endl;
  return 0;
}