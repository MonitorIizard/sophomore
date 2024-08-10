#include <iostream>
using namespace std;

class MaxHeap {
  int heap_size;
  int capacity;
  int *harr;

  public:

  //constructor
  MaxHeap( int capacity ) {
    harr = new int[capacity];
    this->capacity = capacity; //! need to assign precede this on capacity not capacity = capacity
    heap_size = 0;
  };

  //heapify
  void MaxHeapify( int i ) {
    int l = left(i);
    int r = right(i);
    int biggest = i;
    if ( l < heap_size && harr[l] > harr[biggest] ) {
      biggest = l;
    }

    if ( r < heap_size && harr[r] > harr[biggest] ) {
      biggest = r;
    }

    if ( biggest != i ) {
      swap( &harr[i], &harr[biggest] );
      MaxHeapify(biggest);
    }

  }

  //getIndex
  int left( int i ) {return 2*i + 1;}
  int right( int i ) {return 2*i + 2;}
  int parent( int i ) {return (i - 1 ) / 2;}

  //deletion
  int extractMax() { return harr[0]; };
  void deleteMax() {
    cout << extractMax() << endl;
    harr[0] = harr[heap_size-- - 1];
    MaxHeapify(0);
  }

  //insert
  void swap( int* x, int* y ) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  void insertion( int data ) {
    if( heap_size == capacity ) {
      cout << "overflow \n";
      return;
      // resizeArray();
    }

    int i = ++heap_size - 1;
    // insert last index
    harr[i] = data;

    // while( i != 0 && harr[parent(i)] < harr[i]  ) {
    //   swap( &harr[parent(i)], &harr[i] );
    //   i = parent(i);
    // }
  }

  void createHeap( ) {
    int numberOfParent = (heap_size/2);

    for ( int i = numberOfParent-1; i >= 0; i-- ) {
      MaxHeapify(i);
    }
  }

  void levelOrderingTraversal() {
    int i = 0;
    while( i < heap_size ) {
      cout << harr[i] << " ";
      i++;
    }
    cout << endl;
  }

  //resizeArray
  void resizeArray() {
    this->capacity = capacity * 2;
    int *array = new int[capacity];
    
    for( int i = 0; i < sizeof(*harr) / sizeof(harr[0]); i++ ) {
      array[i] = harr[i];
      cout << array[i];
    }

    harr = array;

    delete [] harr;
  }
};

int main() {
  MaxHeap heap1 = MaxHeap(6);

  char command;
  while( command != 'e' ) {
    cin >> command;
    if ( command == 'a' ) {
      int data;
      cin >> data;
      heap1.insertion(data);
    }

    if ( command == 'd' ) {
      heap1.deleteMax();
    }

    if ( command == 'p' ) {
      heap1.levelOrderingTraversal();
    }

    if( command == 'x' ) {
      heap1.createHeap();
      heap1.levelOrderingTraversal();
    } 
  }

  // heap1.deleteMax();
}