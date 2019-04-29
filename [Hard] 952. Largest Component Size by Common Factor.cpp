/*
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:
	Input: [4,6,15,35]
	Output: 4

Example 2:
	Input: [20,50,9,63]
	Output: 2

Example 3:
	Input: [2,3,6,7,4,12,21,39]
	Output: 8

Note:
	1 <= A.length <= 20000
	1 <= A[i] <= 100000
*/

const int N = 200000;
int uf[N];

class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		int m = 0;
		for (int i = 0; i < A.size(); i++) {
			m = max(m, A[i]);
		}
		for (int i = 0; i <= m; i++)
			uf[i] = i;
		for (int i = 0; i < A.size(); i++) {
			int x = sqrt(A[i]);
			for (int j = 2; j <= x; j++) {
				if (A[i] % j == 0) {
					Union(A[i], j);
					Union(A[i], A[i] / j);
				}
			}
		}
		map<int, int> c;
		int res = 1;
		for (int i = 0; i < A.size(); i++) {
			res = max(res, ++c[Find(A[i])]);
		}
		return res;
	}

	void Union(int x, int y) {
		if (Find(x) == Find(y)) return;
		uf[Find(x)] = uf[Find(y)];
	}

	int Find(int x) {
		if (x == uf[x]) return x;
		uf[x] = Find(uf[x]);
		return uf[x];
	}
};