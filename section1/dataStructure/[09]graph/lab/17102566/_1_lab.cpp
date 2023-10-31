// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <iostream>
#include <map>
#include <list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;
  map<pair<int, int>, bool> edge;
  map<pair<int, int>, bool> depthFirstSearchEdge;
  int numberOfNode;

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);

  void Reset() {
    for (map<int, bool>::iterator it=visited.begin(); it!=visited.end(); ++it)
      it -> second = false;
  }

  void printMap() {
    map<pair<int, int>, bool> :: iterator it = edge.begin();
    cout << "Tree Edges : ";
    while(it != edge.end()) {
      if ( it->second == true ) {
        cout << it->first.first << "->" << it->first.second << " ";
      } 
      ++it;
    }

    map<pair<int, int>, bool> :: iterator it2 = edge.begin();

    cout << "\nBack Edges : ";
    while(it2 != edge.end()) {
      if ( it2->second == false ) {
        cout << it2->first.first << "->" << it2->first.second << " ";
      } 
      it2++;
    }
  }
};

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
  edge[make_pair(min(v,w), max(v,w))] = false;
	adj[v].push_back(w);

  // edge.insert({key, [v, w]});
  adj[w].push_back(v);
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin
  (); i != adj[v].end(); ++i) {
		if (!visited[*i]) {
      edge[make_pair(min(v,*i), max(v, *i))] = true;
			DFS(*i);
    }
  }
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;

  int numberOfV;
  int numberOfE;
  cin >> numberOfV;
  cin >> numberOfE;

  int sumOfEdge = 0;

  while ( sumOfEdge < numberOfE ) { 
    int vertex;
    cin >> vertex;

    int vertexToGo;
    cin >> vertexToGo;

    sumOfEdge++;

    if ( vertex > numberOfV ) {
      cout << "vertex is out of range";
      break;
    }
    // if ( sumOfEdge > numberOfE ) {
    //   cout << "edge is out of range";
    //   break;
    // }
	  g.addEdge( vertex, vertexToGo );
  }

  for ( int i = 0; i < numberOfV; i++ ) {
    cout << "Following is Depth First Traversal"
			" (starting from vertex " << i << ") \n";
	  g.DFS(i);
    g.Reset();
    cout << "\n";
  }
  

	return 0;
}

// improved by Vishnudev C
