/*
Given a 2 - dimensional grid of integers, each value in the grid represents the color of the grid square at that location.
Two squares belong to the same connected component ifand only if they have the same colorand are next to each other in any of the 4 directions.
The border of a connected component is all the squares in the connected component that are either 4 - directionally adjacent to a square not in the component, or on the boundary of the grid(the first or last row or column).
Given a square at location(r0, c0) in the gridand a color, color the border of the connected component of that square with the given color, and return the final grid.

Example 1:
	Input: grid = [[1, 1], [1, 2]] , r0 = 0, c0 = 0, color = 3
	Output : [[3, 3], [3, 2]]

Example 2 :
	Input : grid = [[1, 2, 2], [2, 3, 2]] , r0 = 0, c0 = 1, color = 3
	Output : [[1, 3, 3], [2, 3, 3]]

Example 3 :
	Input : grid = [[1, 1, 1], [1, 1, 1], [1, 1, 1]] , r0 = 1, c0 = 1, color = 2
	Output : [[2, 2, 2], [2, 1, 2], [2, 2, 2]]

Note :
	1 <= grid.length <= 50
	1 <= grid[0].length <= 50
	1 <= grid[i][j] <= 1000
	0 <= r0 < grid.length
	0 <= c0 < grid[0].length
	1 <= color <= 1000
*/

const int N = 2508;
int uf[N];

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < N; i++) uf[i] = i;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                if (i != m - 1 && grid[i + 1][j] == grid[i][j]) Union (i * n + j + 1, (i+1) * n + j + 1); 
                if (j != n - 1 && grid[i][j + 1] == grid[i][j]) Union (i * n + j + 1, i * n + j + 1 + 1); 
            }
        }
        int targetcolor = grid[r0][c0];
        int source = Find(r0 * n + c0 + 1);
        map<pair<int, int>, bool> count;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n ; j++) {
                if (Find(i * n + j + 1) == source) {
                    //cout << m << " " << n << " " << Find(i * m + j + 1) << " " << source << endl;
                    if (i == 0 || i == m - 1 || j == 0 || j == n-1) {
                        count[{i , j}] = true;
                        continue;
                    }
                    if (grid[i+1][j] != targetcolor || grid[i-1][j] != targetcolor || grid[i][j+1] != targetcolor || grid[i][j-1] != targetcolor) {
                        count[{i , j}] = true;
                        continue;
                    }
                }
            }
        } 
        for (auto a: count) {
            if (a.second)
                grid[a.first.first][a.first.second] = color;
            //cout << a.first.first << " " << a.first.second << endl;
        }
        
        return grid;
    }
    
    void Union (int x, int y) {
        uf[Find(y)] = Find(uf[x]);
        return;
    }
    
    int Find (int x) {
        if (x != uf[x]) uf[x] = Find(uf[x]);
        return uf[x];
    }
};