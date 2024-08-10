#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//? test case
// 6
// 0 1 2 -1
// 1 0 3 -1
// 2 0 3 -1
// 3 1 2 4 -1
// 4 3 5 -1
// 5 4 -1
// 2 5
void showq(queue<int> gq);

class Graph {
  int size = 6;
  vector< vector< int > > adjacentVector;

public : 
  Graph(int size) {
    this->size = size;

    for ( int i = 0; i < size; i++ ) {
      adjacentVector.push_back( vector<int>(size, 0));
    }
  } ;
  
  void formGraph() {
    int endFlag = -1;
    for ( int vertex = 0; vertex < size; vertex++ ) {
      int neighbor = 0;
      while( neighbor != endFlag ) {
        cin >> neighbor;
        if ( neighbor != vertex ) {
          adjacentVector[vertex][neighbor] = 1;
        }
      }
      
    }
  }

  void showGraph( ) {
  int rowNumber = 0;
    for ( vector< int > vectorRow : adjacentVector ) {
      cout << rowNumber << " : ";

      for ( int element : vectorRow ) {
        cout << element << " ";

      }
      rowNumber++;
      cout << "\n";
    }
  }

  int findShortestDistance(int startNode, int destinationNode) {
    vector<bool> visitedTable;
    visitedTable.resize( size, false );
    
    vector<int> parentChild;
    parentChild.resize( size, -2 );

    queue<int> queue;
    queue.push(startNode);

    visitedTable[startNode] = true;
    parentChild[startNode] = -1;

    cout << endl;

    int head = startNode;
    while( !queue.empty() || head != destinationNode ) {
      head = queue.front();
      queue.pop();
      
      for ( int column = 0; column < size; column++ ) {
        int isNeighbor = adjacentVector[head][column];
        if ( visitedTable[column] == false && isNeighbor == 1 ) {
          visitedTable[column] = true;
          parentChild[column] = head;
          queue.push(column);
        }
      }
    }

    int currentIndex = destinationNode;
    int distanceToDestination = 0;
    while( parentChild[currentIndex] != -1 ) {
      currentIndex = parentChild[currentIndex];
      distanceToDestination++;
    }

    return distanceToDestination;
  } 
};

int main() {
  int size = 6;
  int startNode, destinationNode;

  cin >> size;
  Graph graph(size);

  graph.formGraph();

  

  cin >> startNode;
  cin >> destinationNode;

  int shortestDistance = graph.findShortestDistance(startNode, destinationNode);

  cout << shortestDistance;
  // graph.showGraph();
}

