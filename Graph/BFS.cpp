#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int len = adj.size(); // size of adjacency list
    int start = 0; // source node, starting point

    // storing traversal
    vector<int>traversal;

    // creating queue for BFS
    queue<int>q;

    // Initializing with False
    vector<bool>visited(len, false);

    // marking source node as true
    // and pushing it to the queue
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        // dequeue a node and storing
        int curr = q.front();
        q.pop();
        traversal.push_back(curr);

        // loop through the nodes from adj
        // if it's not visited, mark it true and push into queue
        for (auto it: adj[curr]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }

    }
    
    return traversal; // returning a vector

}

int main() {
    
    return 0;
}