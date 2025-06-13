/*
    @author: ASIF
    Counting Degrees from Adjacency Matrix
    TC: O(e) + O(n^2)
    SC: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

int countDegree(bool adj[][100], int num_of_nodes, int node) {
    node -= 1;
    int count = 0;
    for (int i = 0; i < num_of_nodes; i++) {
            if (adj[node][i] == true) {
                count++;
            }
    }
    return count;
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    // boolean adjacency matrix takes less memory than int
    // Space Complexity: O(n^2) where n = number of nodes
    bool adj[nodes][100] = {};

    // Here, Time Complexity: O(e) where e is number of edges/paths
    for (int i = 0; i < edges; ++i) {
        // input of nodes
        int u, v;
        cin >> u >> v;

        // adding edges
        // u-1 and v-1 because 0 based indexing
        adj[u-1][v-1] = true;
        adj[v-1][u-1] = true;
    }

    // Time Complexity: O(n^2) here. in Total = O(e) + O(n^2)
    for (int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << countDegree(adj, nodes, 1) << '\n';
    cout << countDegree(adj, nodes, 2) << '\n';
    cout << countDegree(adj, nodes, 3) << '\n';
    cout << countDegree(adj, nodes, 4) << '\n';
    cout << countDegree(adj, nodes, 5) << '\n';



    return 0;
}
/*
Sample Input:

5 6
1 2
3 4
1 3
2 4
5 4
2 5

Sample Output:

0 1 1 0 0 
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
0 1 0 1 0

*/
