# Number Of Islands using BFS: Leetcode VS GeekforGeeks

Actually i tried solving both of them with same approach but ended up getting error on one of the platform and got accepted in other platform.

#### Why? Read The Article

## 1st Approach (Diagonal Traversal Allowed)

used two nested loops for delrow and delcol ranging from -1 to 1. This allowed traversal in all 8 directions (up, down, left, right, and diagonals).

```cpp
#include <bits/stdc++.h>
using namespace std;
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


        // traverse in the neigbors
        // and mark them visited
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow; // neighbor row
                int ncol = col + delcol; // neighbor col

                // validity check of nrow and ncol
                // neigbor visited or not 1 or 0
                // neigbnor is a land or not '1' or '0'
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1') {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                } 

            }
        }
         
    }


}
int numIslands(vector<vector<char>> &grid) {
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
                cnt++;
                bfs(row, col, grid, vis);
            }
        }
    }

    return cnt; // returning number of islands

}
int main() {
    
    return 0;
}
```

### Why it worked on GeeksforGeeks?
GeeksforGeeks might have allowed diagonal connections as part of the problem definition. In such cases, two cells are considered part of the same island if they are connected in any of the 8 directions.

This means that diagonal neighbors ((row-1, col-1), (row-1, col+1), etc.) are treated as part of the same island.

### Why it failed on LeetCode?

LeetCode's problem definition for "Number of Islands" explicitly states that two cells are part of the same island only if they are connected in the 4 cardinal directions (up, down, left, right).

Including diagonal neighbors violates this constraint, leading to incorrect results on LeetCode.



## 2nd Approach (Cardinal Directions Only)
Restricted traversal to the 4 cardinal directions using the delrow and delcol arrays:

```cpp
int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};
```

This ensures that only neighbors directly above, below, to the left, or to the right are considered part of the same island.

```cpp
void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
    int n = grid.size();
    int m = grid[0].size();

    // Marking the starting node visited
    vis[row][col] = 1;

    // Taking a queue of pairs to store the lands and then use it by popping
    queue<pair<int, int>> q;

    // Pushing starting land first
    q.push({row, col});

    // Directions for moving in 4 cardinal directions (up, down, left, right)
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // Traverse in the neighbors and mark them visited
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i]; // Neighbor row
            int ncol = col + delcol[i]; // Neighbor col

            // Validity check of nrow and ncol
            // Neighbor visited or not (1 or 0)
            // Neighbor is a land or not ('1' or '0')
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1') {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

```



### Why it works on LeetCode?
LeetCode's problem explicitly requires traversal in the 4 cardinal directions. 

By restricting traversal to these directions, the implementation adheres to the problem's constraints and produces the correct result.

### Why it might still work on GeeksforGeeks?
GeeksforGeeks does not enforce strict constraints on diagonal traversal unless explicitly stated. 

Restricting traversal to 4 directions is still valid and will produce correct results for problems that allow diagonal traversal, as it is a subset of the 8-direction traversal.