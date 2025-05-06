#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(unordered_map<int, vector<int>> &adj, int start) {
    int len = adj.size();
    vector<int>traversal;
    stack<int>st;
    vector<bool>visited(len, false); // track rakhtesi visited gula
    
    visited[start] = true;
    st.push(start);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        traversal.push_back(curr);

        for (auto it: adj[curr]) {
            if (!visited[curr]) {
                visited[curr] = true;
                st.push(it);
            }
            else {
                dfs(adj, );
            }
        }
    }
    // for (auto i: traversal) cout << i << ' ';
    return traversal;
}

void printAdj(unordered_map<int, vector<int>> &adj) {
    int len = adj.size();
    for (auto i: adj) {
        cout << i.first << " -> ";
        for (auto it: i.second) {
            cout << it << ' ';
        }
        cout << endl;
    }
}
int main() {
    int n, m; // number of nodes and edges
    cin >> n >> m;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    printAdj(adj);

    cout << "Enter the start node: "<< endl;
    int start; cin >> start;
    vector<int> res = dfs(adj, start);
    cout << "DFS traversal" << endl;
    
    for (auto it: res) {
        cout << it << " ";
    }

}