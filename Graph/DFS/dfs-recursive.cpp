#include <bits/stdc++.h>
using namespace std;

// Time : O(N + 2E)
// Space: O(N) 
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);

    // traverse all its neigbors
    for (auto it: adj[node]) { // O(2E)
        if(!vis[it]) {
            dfs(it, adj, vis, ls); // O(N)
        }
    }

}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int start = 0;
    vector<int> ls; // to save the traversal path
    dfs(start, adj, vis, ls);
    return ls;
}
int main() {
   
    return 0;
}
