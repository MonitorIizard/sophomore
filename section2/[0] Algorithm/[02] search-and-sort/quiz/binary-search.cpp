#include <iostream>
using namespace std;

int binarySearch( int left, int right, int ascendingData[], int answer ) {
  if ( left <= right ) {
    int mid = ( left + right ) / 2;

    if ( ascendingData[mid] > answer ) {
      return binarySearch(left, mid - 1, ascendingData, answer);
    }

    if ( ascendingData[mid] < answer ) {
      return binarySearch(mid + 1, right, ascendingData, answer);
    }

    if ( ascendingData[mid] == answer ) {
      return answer;
    }
  }

  return -1;
}

int main () {
  int arr[] = {10, 20, 30, 40, 50};
  cout << binarySearch( 0, 4, arr, 20 );

  return 0;
}