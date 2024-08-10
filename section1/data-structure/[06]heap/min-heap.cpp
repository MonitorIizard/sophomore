#include <iostream>
using namespace std;

class Heap {
private:
  int heapSize;
  int* harr;
  int capacity;
public:
  Heap( int capacity ) {
    this -> heapSize = 0;
    this -> capacity = capacity;
    harr = new int[capacity];
  }

  void insert( int data ) {
    if ( heapSize == capacity ) {
      cout << "overflow";
      return;
    }

    harr[heapSize++] = data;
  }

  int extractFirst() {
    int min = harr[0];

    if ( --heapSize >= 0 ) {
      harr[0] = harr[heapSize];
      heapify(0);
    }
    
    return min;
  }

  void heapify( int index ) {
    int l = left( index );
    int r = right( index );
    int smallest = index;

    if ( l < heapSize && harr[l] < harr[index] ) {
      smallest = l;
    }
    if ( r < heapSize && harr[r] < harr[smallest] ) {
      smallest = r;
    }

    if ( smallest != index ) {
      swap( &harr[smallest], &harr[index] );
      heapify(smallest);
    }
  }

  void createHeap() {
    int parentNum = heapSize / 2;

    for ( int i = parentNum - 1 ; i >= 0; i-- ) {
      heapify(i);
    }
  }

  void swap ( int* a, int* b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  int parent( int index ) {
    if ( index == 0 ) {
      return 0;
    }

    return (index - 1) / 2;
  }

  int left( int index ) {
    return (2 *index) + 1;
  }

  int right( int index ) {
    return (2 *index) + 2;
  }

  void printAll() {
    for ( int i = 0; i < heapSize; i++ ) {
      cout << harr[i] << " ";
    }
  }
};

int main() {
  Heap *h = new Heap(7);

  h->insert(50);
  h->insert(45);
  h->insert(35);
  h->insert(20);
  h->insert(10);
  h->insert(5);
  h->insert(12);

  cout << "before heapify\n";
  h->printAll();

  h->createHeap();
  cout << "\nafter heapufy\n";
  h->printAll();

  cout << "\n";
  for ( int i = 0; i < 7; i++ ) {
    cout << h->extractFirst() << " ";
  }
  return 0;
}
