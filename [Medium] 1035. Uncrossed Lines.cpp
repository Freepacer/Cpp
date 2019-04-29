/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.
Now, we may draw a straight line connecting two numbers A[i] and B[j] as long as A[i] == B[j], and the line we draw does not intersect any other connecting (non-horizontal) line.
Return the maximum number of connecting lines we can draw in this way.

Example 1:
	Input: A = [1,4,2], B = [1,2,4]
	Output: 2
	Explanation: We can draw 2 uncrossed lines as in the diagram.
	We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.

Example 2:
	Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
	Output: 3

Example 3:
	Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
	Output: 2

Note:
	1 <= A.length <= 500
	1 <= B.length <= 500
	1 <= A[i], B[i] <= 2000
*/

class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		unordered_map<int, vector<int>> ind;
		for (int i = 0; i < B.size(); i++) {
			ind[B[i]].push_back(i);
		}
		vector<int> dp(B.size(), 0);
		for (int i = 0; i < A.size(); i++) {
			map<int, int> temp;
			if (!ind.count(A[i])) continue;
			for (int j = 0; j < ind[A[i]].size(); j++) {
				temp[ind[A[i]][j]] = 1;
			}
			int curmax = 0;
			for (int k = 0; k < B.size(); k++) {
				if (temp[k] == 1) {
					int x = dp[k];
					dp[k] = max(dp[k], curmax + 1);
					curmax = max(curmax, x);
				}
				else
					curmax = max(curmax, dp[k]);
			}
		}

		int res = 0;
		for (int i = 0; i < dp.size(); i++) {
			res = max(res, dp[i]);
		}
		return res;
	}
};