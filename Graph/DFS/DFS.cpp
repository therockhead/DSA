// used recursive approach
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Adjacency List Preparation
    vector<vector<int>> adj(V); // Use a vector of vectors for adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    vector<bool> visited(V, false); // Use a vector for visited nodes

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E; // number of vertices and edges
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i][0] = u;
        edges[i][1] = v;
    }

    vector<vector<int>> v = depthFirstSearch(V, E, edges);
    for (auto i : v) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}