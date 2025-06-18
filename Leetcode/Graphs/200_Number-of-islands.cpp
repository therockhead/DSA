#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        void bfs(int row, int col, vector<vector<char>> &grid,  vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
    
        // marking the starting node visited
        vis[row][col] = 1;
        
        // taking a queue of pair to store the lands and then use it by poping
        queue<pair<int, int>> q;
        
        // pushing starting land first
        q.push({row, col});
    
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
    
    
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            // traverse in the neigbors
            // and mark them visited
         
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i]; // neighbor row
                    int ncol = col + delcol[i]; // neighbor col
    
                    // validity check of nrow and ncol
                    // neigbor visited or not 1 or 0
                    // neigbnor is a land or not '1' or '0'
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol]== '1') {
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                    } 
    
                }
            
             
        }
    
    
    }
    public:
        int numIslands(vector<vector<char>>& grid) {
            // row size and column size
        int n = grid.size();
        int m = grid[0].size();
    
        // vis 2D matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
    
        // to store the number of islands
        int cnt = 0;
    
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    
                    bfs(row, col, grid, vis);
                    cnt++;
                }
            }
        }
    
        return cnt; // returning number of islands
        }
    };