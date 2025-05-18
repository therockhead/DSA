#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int edge_id[100];
bool vis[100];

void dfs(int s, int n) {
	for (int i = 0; i < n; i++) {
		edge_id[i] = vis[i] = 0;
	}
	stack<int> S;
	S.push(s);

	while (!S.empty()) {
		int u = S.top();
		S.pop();

		while(edge-id[u] < adj[u].size()) {
			// start looking into edges, from
			// the index we left
			int v =adj[u][edges_id[u]];
			// update edge pointer to check
			// next time
			edge_id[u]++;
			// if the vertex is not yet visited
			if (vis[v] == 0) {
				vis[v] = 1;
				S.push(u);
				// FIrst we will check v, then we
				// will come back to u
				S.push(v);
				// Stack is LIFO
				// So v will be popped before u
				break;
			}
		}
	}

}

int main() {
	

}
