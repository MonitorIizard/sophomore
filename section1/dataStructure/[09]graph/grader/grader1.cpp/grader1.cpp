#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Edge {
  public : 
    double weight;
    int vertex;

    Edge( int vertex, double weigth ) {
      this->vertex = vertex;
      this -> weight = weight;
    }
};

class Graph {
  public:
    map<int, bool> visited;
    map<int, list<Edge> > adj;
    
    void addEdge( int v, int w, int weight ) {
      Edge destination = Edge(w, weight);
      list<Edge> :: iterator i;

      for ( i = adj[v].begin(); i != adj[v].end(); i++ ) {
        if ( (*i).vertex > w ) {
          adj[v].insert(i, destination);
          break;
        }
      }

      if ( i == adj[v].end() ) adj[v].push_back( destination );
    }

    // void sort () {
    //   map<int, list<Edge> > :: iterator i = adj.begin();
    //   for ( ; i != adj.end(); i++ ) {
    //     i->second.sort();
    //   }
    // }

    void dfs( int v ) {
      visited[v] = true;
      cout << v << " ";
      list<Edge> :: iterator i;

      for ( i = adj[v].begin(); i != adj[v].end(); i++ ) {
        if ( !visited[(*i).vertex]) {
          dfs((*i).vertex);
        }
      }
    }

    void bfs( int v ) {
      visited[v] = true;
      queue<int> queue;
      queue.push(v);

      while( queue.size() != 0 ) {
        int v = queue.front();
        cout << v << " ";
        queue.pop();

        for ( list<Edge> :: iterator i = adj[v].begin();              
              i != adj[v].end();
              i++ ) {

                if( visited[(*i).vertex] != true ) {
                  visited[(*i).vertex] = true;
                  queue.push((*i).vertex);
                }
              }
        }
    }

    void printAllAdjList() {
      map<int, list<Edge> > :: iterator i = adj.begin();
      
      for (; i != adj.end(); i++ ) {
        cout << "at v = " << i -> first;
        cout << "\n";
        for(list<Edge> :: iterator j = i->second.begin(); j != i->second.end();j++ ) {
          cout << (*j).vertex << " ";
        }

        cout << "\n";
      }

    }

    void resetVisited() {
      map< int, bool> :: iterator i = visited.begin();
      for (; i != visited.end(); i++ ) {
        i -> second = false;
      }
    }
};

int main() {
  Graph g = Graph();
  char command;
  int numberOfVertex;
  cin >> numberOfVertex;

  while( command != 's' || g.adj.size() < numberOfVertex) {
    cin >> command;

    if ( command == 'e' ) {
      int vertex, w;
      double weight;
      cin >> vertex;
      cin >> w;
      cin >> weight;

      g.addEdge(vertex, w, weight);
    }
  }

  while( command != 'q' ) {
    cin >> command;

    if ( command == 'd' ) {
      int vertex;
      cin >> vertex;
      g.resetVisited();
      g.dfs(vertex);
      cout << "\n";
    }

    if ( command == 'b' ) {
      int vertex;
      cin >> vertex;
      g.resetVisited();
      g.bfs(vertex);
      cout << "\n";
    }
  }

  return 0;
}

