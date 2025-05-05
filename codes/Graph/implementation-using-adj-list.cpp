// Graph implementation using adjacency List
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// IMPORTANT //
template <typename T> // to make it usable for any datatype
// for example: Graph<int>g, Graph<char>g etc..

// Defining Graph Class
class Graph{
// unordered map of an int value and a list
  public:
    unordered_map<T, list<int>> adj; // replaced int with T 
    void addEdge(T u, T v, bool direction) { // replaced int with T
        // create an edge from u to v
        adj[u].push_back(v);
        // direction = true -> directed graph
        // direction = false -> undirected graph
        if (direction == false) {
            adj[v].push_back(u);
        }
    }
    void printAdjList() {
        for (auto i:adj) {
            cout << i.first << "->";
            for (auto j: i.second) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

// Main Function
int main() {
    cout << "Enter number of nodes and edges: ";
    int n, m; // number of nodes and edges
    cin >> n >> m;
    Graph<int>g; // taking a Graph type variable
    // using <int> because we made a template 
    // this enables us to use Graph for other data types too!
    for (int i = 0; i < m; i++) {
        int u, v; // input of two node point
        cin >> u >> v;
        g.addEdge(u, v, false); // addEdge(u, v, direction)
    }
    g.printAdjList();
    return 0;
}