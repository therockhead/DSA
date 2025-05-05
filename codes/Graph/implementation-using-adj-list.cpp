// Graph implementation using adjacency List
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
// unordered map of an int value and a list
  public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction) {
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
                cout << j << ", ";
            }
            cout << "\n";
        }
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}