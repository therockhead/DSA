#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100]; // 0 if not visited, 1 if visited

// s is the starting vertex
// n is the number of vertices (0,1,2,...n-1)
void bfs(int s, int n) { 
	for (int i = 0; i< n; i++) {
		visited[i] = 0;
	}
	queue<int> Q;
	Q.push(s); // pushing starting node in the Queue
	visited[s] = 1;

	while (!Q.empty()) {
		int u = Q.front(); // taking the front from the queue
		Q.pop(); // removing the front

		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == 0) {
				// if not visited
				int v = adj[u][i];
				visited[v] = 1;
				Q.push(v);
			}

		}
	}
}
int main() {
	
}
