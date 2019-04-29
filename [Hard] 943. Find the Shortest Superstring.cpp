/*
Given an array A of strings, find any smallest string that contains each string in A as a substring.

We may assume that no string in A is substring of another string in A.

Example 1:
	Input: ["alex","loves","leetcode"]
	Output: "alexlovesleetcode"
	Explanation: All permutations of "alex","loves","leetcode" would also be accepted.

Example 2:
	Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
	Output: "gctaagttcatgcatc"

Note:
	1 <= A.length <= 12
	1 <= A[i].length <= 20
*/

class Solution {
public:
	string shortestSuperstring(vector<string>& A) {
		const int n = A.size();
		g_ = vector<vector<int>>(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				g_[i][j] = A[j].length();
				for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
					if (A[i].substr(A[i].size() - k) == A[j].substr(0, k))
						g_[i][j] = A[j].length() - k;
			}
		vector<int> path(n);
		best_len_ = INT_MAX;
		dfs(A, 0, 0, 0, path);
		string ans = A[best_path_[0]];
		for (int k = 1; k < best_path_.size(); ++k) {
			int i = best_path_[k - 1];
			int j = best_path_[k];
			ans += A[j].substr(A[j].length() - g_[i][j]);
		}
		return ans;
	}
private:
	vector<vector<int>> g_;
	vector<int> best_path_;
	int best_len_;
	void dfs(const vector<string> & A, int d, int used, int cur_len, vector<int> & path) {
		if (cur_len >= best_len_) return;
		if (d == A.size()) {
			best_len_ = cur_len;
			best_path_ = path;
			return;
		}

		for (int i = 0; i < A.size(); ++i) {
			if (used & (1 << i)) continue;
			path[d] = i;
			dfs(A,
				d + 1,
				used | (1 << i),
				d == 0 ? A[i].length() : cur_len + g_[path[d - 1]][i],
				path);
		}
	}
};