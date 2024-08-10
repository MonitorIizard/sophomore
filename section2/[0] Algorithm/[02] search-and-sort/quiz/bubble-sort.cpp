#include <iostream>
using namespace std;

void bubbleSort(int rawData[], int size) {
  for ( int i = 0; i < size; i++ ) {
    for ( int j = 0; j < size; j++ ) {
      if ( rawData[j] > rawData[i] ) {
        int temp = rawData[i];
        rawData[i] = rawData[j];
        rawData[j] = temp;

      }

    }
  }
}

void printElement( int* arr, int size ) {
  int i = 0;

  while ( i < size ) {
    cout << arr[i] << "";
    i++;
  }

  cout << endl;
}
int main() {
  int size = 5;
  int rawData[] = { 50, 40, 30, 20, 10 };

  bubbleSort( rawData, size );

  printElement( rawData, size );
  return 0;
}