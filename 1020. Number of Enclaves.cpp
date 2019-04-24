/*
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)
A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.
Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
	Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
	Output: 3
	Explanation:
	There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.

Example 2:
	Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
	Output: 0
	Explanation:
	All 1s are either on the boundary or can reach the boundary.

Note:
	1 <= A.length <= 500
	1 <= A[i].length <= 500
	0 <= A[i][j] <= 1
	All rows have the same size.
*/

class Solution {
public:
	int numEnclaves(vector<vector<int>>& A) {
		int res = 0;
		map<pair<int, int>, int> past;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A[0].size(); j++) {
				bool good = false;
				if (A[i][j] != 0)
				{
					helper(A, past, i, j, good);
					if (good)
					{
						for (auto a : past)
						{
							if (A[a.first.first][a.first.second] == 1)
								A[a.first.first][a.first.second] = 2;
						}
					}
					else
					{
						res++;
						for (auto a : past)
						{
							if (A[a.first.first][a.first.second] == 1)
								A[a.first.first][a.first.second] = -2;
						}
					}
					past.clear();
				}
			}
		}
		return res;
	}

	void helper(vector<vector<int>> & A, map<pair<int, int>, int> & past, int i, int j, bool& good) {
		if (i<0 || j<0 || i>A.size() - 1 || j>A[0].size() - 1 || past[{i, j}] == 1 || good == true || A[i][j] == 0 || A[i][j] == -2) {
			if (A[i][j] == 1)
				past[{i, j}] = 1;
			return;
		}
		if (((i == 0 || j == 0 || i == A.size() - 1 || j == A[0].size() - 1) && A[i][j] == 1) || A[i][j] == 2) {
			good = true;
			past[{i, j}]++;
			return;
		}
		past[{i, j}]++;
		helper(A, past, i + 1, j, good);
		helper(A, past, i - 1, j, good);
		helper(A, past, i, j + 1, good);
		helper(A, past, i, j - 1, good);
		return;
	}
};