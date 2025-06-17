#include <bits/stdc++.h>
using namespace std;

bool dfsFindPath(int node, int target, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &path) {
    visited[node] = true;
    path.push_back(node);

    if (node == target) {
        return true; // Target node found
    }

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsFindPath(neighbor, target, visited, adj, path)) {
                return true; // Stop DFS once the target is found
            }
        }
    }

    path.pop_back(); // Backtrack if the target is not found in this path
    return false;
}

vector<int> findPathToTarget(int V, int E, vector<vector<int>> &edges, int target) {
    // Adjacency List Preparation
    vector<vector<int>> adj(V); // Use a vector of vectors for adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false); // Use a vector for visited nodes
    vector<int> path;

    // Start DFS from node 0 (or any other starting node)
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsFindPath(i, target, visited, adj, path)) {
                break; // Stop once the path to the target is found
            }
        }
    }
    return path;
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

    cout << "\nWhich node do you want to find the path to?" << endl;
    int target;
    cin >> target;

    vector<int> target_path = findPathToTarget(V, E, edges, target);

    if (!target_path.empty()) {
        cout << "Path towards the target node: ";
        for (auto node : target_path) {
            cout << node << ' ';
        }
        cout << endl;
    } else {
        cout << "No path found to the target node." << endl;
    }
    return 0;
}