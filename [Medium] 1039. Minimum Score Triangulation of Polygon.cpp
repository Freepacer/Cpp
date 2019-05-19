/*
Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.
Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.
Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Example 1:
	Input: [1,2,3]
	Output: 6
	Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

Example 2:
	Input: [3,7,4,5]
	Output: 144
	Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.

Example 3:
	Input: [1,3,1,4,1,5]
	Output: 13
	Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

Note:
	1. 3 <= A.length <= 50
	2. 1 <= A[i] <= 100
*/

class Solution {
public:
	static const int MAX = 55;
	static const int INF = 1e9 + 5;

	int n;
	vector<int> A;
	int dp[MAX][MAX];

	int prev(int x) {
		return (x + n - 1) % n;
	}

	int next(int x) {
		return (x + 1) % n;
	}

	int solve(int start, int end) {
		if (start == end || next(start) == end || prev(start) == end)
			return 0;

		int& answer = dp[start][end];

		if (answer >= 0)
			return answer;

		answer = INF;

		for (int i = next(start); i != end; i = next(i))
			answer = min(answer, A[start] * A[i] * A[end] + solve(start, i) + solve(i, end));

		return answer;
	}

	int minScoreTriangulation(vector<int> & _A) {
		A = _A;
		n = A.size();
		memset(dp, -1, sizeof(dp));
		int best = INF;

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					best = min(best, A[i] * A[j] * A[k] + solve(i, j) + solve(j, k) + solve(k, i));

		return best;
	}
};