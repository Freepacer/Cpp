/*
On a 2-dimensional grid, there are 4 types of squares:
	1 represents the starting square.  There is exactly one starting square.
	2 represents the ending square.  There is exactly one ending square.
	0 represents empty squares we can walk over.
	-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
	Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
	Output: 2
	Explanation: We have the following two paths:
	1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
	2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:
	Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
	Output: 4
	Explanation: We have the following four paths:
	1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
	2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
	3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
	4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:
	Input: [[0,1],[2,0]]
	Output: 0
	Explanation:
	There is no path that walks over every empty square exactly once.
	Note that the starting and ending square can be anywhere in the grid.

Note:
	1 <= grid.length * grid[0].length <= 20
*/

class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int res = 0;
		int count = 0;
		int row = 0;
		int col = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0)
					count++;
				if (grid[i][j] == 1) {
					row = i;
					col = j;
				}
			}
		}
		map<pair<int, int>, bool> temp;
		helper(grid, row, col, count, res, temp);
		return res;
	}

	void helper(vector<vector<int>>& grid, int row, int col, int count, int& res, map<pair<int, int>, bool> temp) {
		if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1 || temp[{row, col}]) {
			return;
		}
		if (grid[row][col] == 2 && count != 0) {
			return;
		}
		if (grid[row][col] != 1 && count > 0)
			count--;
		if (grid[row][col] == 2 && count == 0) {
			res++;
			return;
		}
		map<pair<int, int>, bool> temp2 = temp;
		temp2[{row, col}] = true;
		helper(grid, row + 1, col, count, res, temp2);
		helper(grid, row - 1, col, count, res, temp2);
		helper(grid, row, col + 1, count, res, temp2);
		helper(grid, row, col - 1, count, res, temp2);
		return;
	}
};
