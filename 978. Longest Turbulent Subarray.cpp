/*
A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:
	For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
	OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
	That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
Return the length of a maximum size turbulent subarray of A.

Example 1:
	Input: [9,4,2,10,7,8,8,1,9]
	Output: 5
	Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])

Example 2:
	Input: [4,8,12,16]
	Output: 2

Example 3:
	Input: [100]
	Output: 1

Note:
	1 <= A.length <= 40000
	0 <= A[i] <= 10^9
*/

class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		if (A.size() <= 1) return A.size();
		int curres = 1;
		int res = 0;
		bool oddpeak;
		bool evenpeak;
		for (int i = 0; i < A.size(); i++) {
			if (i == 0) continue;
			if (i % 2 == 0) {
				if (A[i] > A[i - 1]) {
					if (oddpeak) {
						res = max(res, curres);
						curres = 2;
						oddpeak = false;
						evenpeak = true;
						continue;
					}
					curres++;
					oddpeak = false;
					evenpeak = true;
					continue;
				}
				if (A[i] < A[i - 1]) {
					if (evenpeak) {
						res = max(res, curres);
						curres = 2;
						oddpeak = true;
						evenpeak = false;
						continue;
					}
					curres++;
					oddpeak = true;
					evenpeak = false;
					continue;
				}
				if (A[i] == A[i - 1]) {
					res = max(res, curres);
					curres = 1;
					oddpeak = false;
					evenpeak = false;
					continue;
				}
			}
			if (i % 2 == 1) {
				if (A[i] > A[i - 1]) {
					if (evenpeak) {
						res = max(res, curres);
						curres = 2;
						oddpeak = true;
						evenpeak = false;
						continue;
					}
					curres++;
					oddpeak = true;
					evenpeak = false;
					continue;
				}
				if (A[i] < A[i - 1]) {
					if (oddpeak) {
						res = max(res, curres);
						curres = 2;
						oddpeak = false;
						evenpeak = true;
						continue;
					}
					curres++;
					oddpeak = false;
					evenpeak = true;
					continue;
				}
				if (A[i] == A[i - 1]) {
					res = max(res, curres);
					curres = 1;
					oddpeak = false;
					evenpeak = false;
					continue;
				}
			}

		}
		res = max(res, curres);
		return res;
	}
};