#include <iostream>
using namespace std;

// Prototype of a utility function to do swap two integers.
void swap(int *x, int *y);

class MinHeap {
  int *harr; // pointer return array
  int capacity; // maximum heap size
  int heap_size; // current number of min heap

  public: 
  MinHeap( int capacity );

  void MinHeapify( int i );

  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }

  int extractMin();

  void decreaseKey( int i, int newValue );

  int getMin() { return harr[0]; }

  void deleteKey( int i ); 

  void insertKey( int k );

};

MinHeap:: MinHeap( int capacity ) {
  heap_size = 0;
  capacity = capacity;
  harr = new int[capacity];
}

void MinHeap:: insertKey(int k) {
  if( heap_size == capacity ) {
    cout << "overflow";
    return;
  }

  heap_size++;
  int i = heap_size - 1;
  harr[i] = k;

  while( i != 0 && harr[parent(i)] > harr[i]) {
    swap(&harr[parent(i)], &harr[i]);
    i = parent(i);
  }
}

void MinHeap:: decreaseKey( int i, int new_value ) {
  harr[i] = new_value;
  while( i != 0 && harr[parent(i)] > harr[i] ) {
    swap(&harr[parent(i)], &harr[i]);
    i = parent(i);
  }
}

int MinHeap:: extractMin()  {
  if( heap_size <= 0 ) {
    return INT_MAX;
  }
  if( heap_size == 1 ) {
    heap_size--;
    return harr[0];
  }

  int root = harr[0];
  harr[0] = harr[heap_size - 1];
  heap_size--;
  MinHeapify(0);

  return root;

}

void MinHeap:: deleteKey( int i ) {
  decreaseKey( i, INT_MIN );
  extractMin();
}

void MinHeap:: MinHeapify( int i ) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if( l < heap_size && harr[l] < harr[i]) {
    smallest = l;
  }
  if( r < heap_size && harr[r] < harr[smallest]) {
    smallest = r;
  }
  if ( smallest != i ) {
    swap(&harr[smallest], &harr[i]);
    MinHeapify(smallest);
  }
}

void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}