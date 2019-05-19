/*
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.

Example 1:
	Input: A = [1,15,7,9,2,5,10], K = 3
	Output: 84
	Explanation: A becomes [15,15,15,9,10,10,10]

Note:
	1. 1 <= K <= A.length <= 500
	2. 0 <= A[i] <= 10^6
*/

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		map<int, int> cursum;
		for (int i = 0; i < A.size(); i++) {
			int cur = 0;
			for (int j = i; j >= max(0, i - K + 1); j--) {
				cur = max(cur, A[j]);
			}
			cursum[i] = cur;
		}
		int n = A.size();
		int dp[n];
		for (int i = 0; i < n; i++) {
			if (i < K) {
				dp[i] = cursum[i] * (i + 1);
			}
			else {
				int cur = 0;
				int curres = 0;
				for (int j = i; j > i - K; j--) {
					cur = max(cur, A[j]);
					curres = max(curres, dp[j - 1] + (i - j + 1) * cur);
				}
				dp[i] = curres;
			}
		}
		return dp[n - 1];
	}
};