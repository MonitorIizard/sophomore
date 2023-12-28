#include <iostream>
using namespace std;

class Node {
public:
  int point;
  char type;  

  Node( int point, char type ) {
    this->point = point;
    this->type = type;
  }

  Node( ) {
    this->point = 0;
    this->type = 'n';
  }
};

class minHeap {
private:
  Node *harr;
  int maxSize;
  int length;
public:
  minHeap( int capacity ) {
    harr = new Node[capacity];
    maxSize = capacity;
    length = 0;
  }

  int parent( int index ) {
    return ( index - 1 ) / 2;
  }

  int left( int index ) {
    return ( 2 * index ) + 1;
  }

  int right( int index ) {
    return ( index * 2 ) + 2;
  }

  int getLength() {
    return this->length;
  }

  Node extractMin ( ) {
    if ( length <= 0 ) {
      return * new Node();
    }

    Node toBeExtracted = harr[0];
    harr[0] = harr[length-1];

    heapify(0);

    if ( length > 0 ) {
      length--;
    }

    return toBeExtracted;
  }

  void insertHeap( int point, int type ) {
    // cout << point << " ";
    Node *newNode = new Node( point, type );
    harr[ length++ ] = *newNode;
    // harr[ length++ ].point = 5;
  }

  void printAll( ) {
    // swap( &harr[5], &harr[4] );
    // for ( int i = 0; i < length; i++ ) {
    //   cout << harr[ i ].point << " ";
    // }

    while ( length > 0 ) {
      Node min = extractMin();
      cout << "type : " << min.type << " " << "point : " << min.point << ", " << endl;
    }
  }

  void swap( Node *x, Node *y ) {
    Node temp = *x;
    *x = *y;
    *y = temp;
  }

  void buildHeap() {
    int numberOfParent = length / 2;

    for ( int i = numberOfParent - 1; i >= 0; i-- ) {
      heapify( i  );
    } 
  }

  void heapify( int index ) {

    int l = left( index );
    int r = right( index );
    int smallest = index;

    if ( r < length && harr[r].point < harr[smallest].point ) {
      smallest = r;
    } 

    // if ( harr[] )
    
    if ( l < length && harr[l].point < harr[smallest].point ){
      smallest = l;
    }

    if ( l < length && harr[smallest].point == harr[l].point  && harr[l].type == 'i'){
      smallest = l;
    }

    if ( r < length && harr[smallest].point == harr[r].point  && harr[r].type == 'i'){
      smallest = r;
    }

    if ( smallest != index ) {
      swap( &harr[smallest], &harr[index] );
      heapify( smallest );
    }
  }
};

class commonTime {
public :
  int startPoint;
  int endPoint;
  int numberOfCustomers;

  commonTime() {
    startPoint = 0;
    endPoint = 0;
    numberOfCustomers = 0;
  }

  commonTime( int sp, int ep, int noc ) {
    this->startPoint = sp;
    this->endPoint = ep;
    this->numberOfCustomers = noc;
  }

};

int main() { 
  int numberOfCustomers;
  cin >> numberOfCustomers;

  commonTime *customersCount[numberOfCustomers];

  for ( int i = 0; i < numberOfCustomers; i++ ) {
    customersCount[i] = new commonTime();
  }

  minHeap *minheap = new minHeap(numberOfCustomers * 2);

  for ( int i = 0; i < numberOfCustomers; i++ ) {
    int startPoint;
    int endPoint;
    cin >> startPoint;
    cin >> endPoint;

    minheap->insertHeap(startPoint, 'i');
    minheap->insertHeap(endPoint, 'o');
  }

  minheap->buildHeap();

  int currentlyCustCount = 0;
  int currentIndex = 0;
  int length = minheap->getLength();
  int sp = 0;
  int mostCount = 0;
  int k = length;
  while ( k > 0 ) {
    Node min = minheap->extractMin();

    if ( min.type == 'i' ) {
      currentlyCustCount++;
      sp = min.point;
    }

    if ( min.type == 'o' ) {
      // stamp currently customer count for each intersect time interval;
      int ep = min.point;

      if ( mostCount <= currentlyCustCount ) {
        customersCount[currentIndex++] = new commonTime(sp, ep, currentlyCustCount);
        mostCount = currentlyCustCount;
      }

      currentlyCustCount--;
    }

    k--;
  }

  int streak = 0;
  int startPoint = 0;
  int endPoint = 0;
  for ( int i = 0; i < numberOfCustomers; i++ ) {

    if ( customersCount[i]->numberOfCustomers == mostCount ) {
      if ( streak != 1 ) {
        startPoint = customersCount[i]->startPoint; 
        endPoint = customersCount[i]->endPoint;
        streak = 1;
      }

      if ( streak == 1 && customersCount[i]->numberOfCustomers == mostCount ) {
        endPoint = customersCount[i]->endPoint;
      } else {
        break;
      }
    }
  }

  cout << startPoint << " " << endPoint << " " << mostCount;

  // for ( int i = 0; i < numberOfCustomers; i++ ) {
  //   cout << "i : " << i << " " << customersCount[i]->numberOfCustomers << endl;
  //   cout << "in : " << customersCount[i]->startPoint << "end : " << customersCount[i]->endPoint << endl << endl;
  // }
  // // minheap->printAll();

  return 0;
}
