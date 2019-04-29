/*
On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 0 <= y < N has a lamp.
Initially, some number of lamps are on.  lamps[i] tells us the location of the i-th lamp that is on.  
Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).
For the i-th query queries[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0.
After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally 
(ie., share a corner or edge with cell (x, y).)
Return an array of answers.  Each value answer[i] should be equal to the answer of the i-th query queries[i].

Example 1:
	Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
	Output: [1,0]
	Explanation:
	Before performing the first query we have both lamps [0,0] and [4,4] on.
	The grid representing which cells are lit looks like this, where [0,0] is the top left corner, and [4,4] is the bottom right corner:
	1 1 1 1 1
	1 1 0 0 1
	1 0 1 0 1
	1 0 0 1 1
	1 1 1 1 1
	Then the query at [1, 1] returns 1 because the cell is lit.  After this query, the lamp at [0, 0] turns off, and the grid now looks like this:
	1 0 0 0 1
	0 1 0 0 1
	0 0 1 0 1
	0 0 0 1 1
	1 1 1 1 1
	Before performing the second query we have only the lamp [4,4] on.  Now the query at [1,0] returns 0, because the cell is no longer lit.

Note:
	1 <= N <= 10^9
	0 <= lamps.length <= 20000
	0 <= queries.length <= 20000
	lamps[i].length == queries[i].length == 2
*/

class Solution {
public:
	vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		map<int, int> row;
		map<int, int> column;
		map<int, int> add;
		map<int, int> subtract;
		map<pair<int, int>, int> l;
		vector<int> res;
		for (int i = 0; i < lamps.size(); i++) {
			int x = lamps[i][0];
			int y = lamps[i][1];
			row[x]++;
			column[y]++;
			add[x + y]++;
			subtract[x - y]++;
			l[{x, y}] = 1;
		}
		for (int i = 0; i < queries.size(); i++) {
			int x = queries[i][0];
			int y = queries[i][1];
			if (row[x] || column[y] || subtract[x - y] || add[x + y])
				res.push_back(1);
			else
				res.push_back(0);
			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					auto it = l.find(make_pair(i, j));
					if (it != l.end() && it->second > 0) {
						--it->second;
						row[i]--;
						column[j]--;
						add[i + j]--;
						subtract[i - j]--;
					}
				}
			}
		}
		return res;
	}
};
