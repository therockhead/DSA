#include <bits/stdc++.h>
using namespace std;

// vector<int> adj[100];
// int edges_id[100];
// bool vis[100];

void dfs(int s, int n, vector<int> adj[], int edges_id[], bool vis[], vector<int> &dfsPath)
{
	for (int i = 0; i < n; i++)
	{
		edges_id[i] = vis[i] = 0;
	}
	stack<int> S;
	S.push(s);

	while (!S.empty())
	{
		int u = S.top();
		S.pop();
		if (!vis[u]) {
			vis[u] = true;
			dfsPath.push_back(u);
		}
		

		while (edges_id[u] < adj[u].size())
		{
			// start looking into edges, from
			// the index we left
			int v = adj[u][edges_id[u]];
			// update edge pointer to check
			// next time
			edges_id[u]++;
			// if the vertex is not yet visited
			if (!vis[v])
			{
				// dfsPath.push_back(u);
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

int main()
{

	int n, m;
	cin >> n >> m;
	// n = number of nodes
	// m = number of edges

	// parameters
	vector<int> adj[n];
	bool vis[n];
	int edges_id[n];
	vector<int> dfsPath;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// calling dfs func and sending reference parameters
	dfs(2, 5, adj, edges_id, vis, dfsPath);

	cout << "DFS path: ";
	for (auto node: dfsPath) {
		cout << node << ' ';
	}

	return 0;
}
