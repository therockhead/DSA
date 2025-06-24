#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true; 
                }
            }
        }

        int tm = 0;
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int first_row = q.front().first.first;
            int first_col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            tm = max(tm, time);

            for (int i = 0; i < 4; i++) {
                int new_row = first_row + del_row[i];
                int new_col = first_col + del_col[i];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m 
                    && !vis[new_row][new_col] && grid[new_row][new_col] == 1) {
                    
                    q.push({{new_row, new_col}, time + 1});
                    vis[new_row][new_col] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return tm;
    }
};
