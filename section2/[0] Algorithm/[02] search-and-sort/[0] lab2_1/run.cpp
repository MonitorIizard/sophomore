#include <iostream>
#include <math.h>
using namespace std;

int interpolationSearch(int arr[], int left, int right, int target ) {
  int new_probe = left + floor( ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]));

  if ( target != arr[new_probe] ) {
    cout << new_probe << " ";
  } else {
    cout << new_probe;
  }

  if ( arr[new_probe] == target ) return new_probe;

  if ( arr[new_probe] > target ) {
    return interpolationSearch(arr, left, new_probe - 1, target );
  }

  if ( arr[new_probe] < target ) {
    return interpolationSearch(arr, new_probe + 1, right, target );
  }
}

int main () {
  int number_of_elem;
  int target;

  cin >> number_of_elem;
  cin >> target;

  int arr[number_of_elem];
  
  for ( int i = 0; i < number_of_elem; i++ ) {
    int data;
    cin >> data;
    arr[i] = data;
  }

  interpolationSearch(arr, 0, number_of_elem - 1, target );
  return 0;
}