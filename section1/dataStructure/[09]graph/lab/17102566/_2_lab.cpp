#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Graph
{
    int V;
    vector<list<int> > adj;
    map<pair<int, int>, bool> walked_edges;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void print_back_edges();
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);

	pair<int, int> edgeCurr;
	edgeCurr.first = v;
	edgeCurr.second = w;
	pair<int, int> edgeCurrRev;
	edgeCurrRev.first = w;
	edgeCurrRev.second = v;

	walked_edges[edgeCurr] = false;
	walked_edges[edgeCurrRev] = false;
}

void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        std::list<int>::iterator it;
        for (it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if (!visited[*it])
            {
                pair<int, int> curr_edge;
                curr_edge.first = s;
                curr_edge.second = *it;
                pair<int, int> curr_edge_reverse;
                curr_edge_reverse.first = *it;
                curr_edge_reverse.second = s;

                cout << "(" << s << "," << *it << ")" << endl;

                walked_edges[curr_edge] = true;
                walked_edges[curr_edge_reverse] = true;

                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
}


void Graph::print_back_edges()
{
	map<pair<int, int>, bool>::iterator it = walked_edges.begin();

	cout << "Cross edges: " << endl;

	while (it != walked_edges.end())
	{
		if (it->second == false)
		{
			cout << "(" << it->first.first << "," << it->first.second << ")" << endl;
		}
		++it;
	}
}

int main()
{
    int vertice_count, edge_count;
    cin >> vertice_count;
    cin >> edge_count;

    Graph g(vertice_count);

    int v, w;
    for (int i = 0; i < edge_count; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cin >> v;
    cout << "Tree edges: " << endl;
    g.BFS(v);

    g.print_back_edges();

    return 0;
}