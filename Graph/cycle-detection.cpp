/*Intiution
    started with two different paths
    and end up getting at a common point
*/

// Time Complexity O(N+ 2E) // 2E because it is undirected
// Space Complexity O(N) for using Queue
#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;
    queue<pair<int, int>> q; // to store the node and the parent
    q.push({src, -1}); // at first node, its parent is -1
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode: adj[node]) {
            if (!vis[adjacentNode]) { // if not visited
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
             }
            else if(parent != adjacentNode) { 
                // if visited 
                // if it's not the parent, then
                // it might be the node which was
                // visited by another path
                // so there exists a cycle
                return true;
            }
         }
     }
    return false;
}

int main() {
    
     
    
    return 0;
}