/*
    This program finds distance of each node from the source
*/

#include <bits/stdc++.h>
using namespace std;

vector<int>  bfsPath(vector<vector<int>> &adj, int source, int target) {
    int nodes = adj.size(); 

    // taking a queue
    queue<int>q;
    // this will contain the distance of each node
    vector<int>level(nodes, 1e9);

    q.push(source);
    level[source] = 0; // start node distance will be 0,
    // means start/source node is in the level 0
    int p[nodes];
    p[source] = 0;

    while(!q.empty()) {
        int node = q.front(); // take the front of the queue
        q.pop(); // remove that element

        for (int neighbour : adj[node]) {
             // now traverse all the neigbours
            // of the node which was just popped
            if (level[neighbour] == 1e9) {
                // update the levels of the adjacent nodes
                // adjacent nodes will hold [level of parent node+1]
                level[neighbour] = level[node] + 1;
                p[neighbour] = node;
                // pushing neigbours to the queue
                // for future pop and assign level
                q.push(neighbour);

            }
        }
    }

    vector<int>path;
    path.push_back(target);
    int now = target;
    // in vector path, the entire path is in reverse order
    while (now != source) {
        now = p[now];
        path.push_back(now);
    }
    cout<<"========================================\n";
    cout << "Path: ";
    for (int i = path.size()-1; i >= 0; i--) cout << path[i] << ' ';
    cout << '\n';
    // at last returning level
    // distance of each node from the source node
    return level;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes+1);

    for (int i = 1; i <= edges; i++) {
        
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    cout << "Source Node: " << endl;
    int source; cin >> source;

    cout << "Target Node: " << endl;
    int target; cin >> target;

    vector<int>level = bfsPath(adj, source, target);

    cout << "distance of nodes from the source node "<< source << " to target node "<< target << endl;
    for (int i = 1; i < level.size();i++) cout << level[i] << ' ';


    return 0;
}

/*
     10 13
        1 2
        1 4
        1 3
        2 6
        4 7
        3 8
        3 7
        6 10
        7 9
        7 8
        9 10
        10 5
        5 8
        

*/