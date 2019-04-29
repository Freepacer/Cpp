/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s.

Example 1:
	Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
	Output: 6
	Explanation:
	[1,1,1,0,0,1,1,1,1,1,1]
	Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Example 2:
	Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
	Output: 10
	Explanation:
	[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
	Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.

Note:
	1 <= A.length <= 20000
	0 <= K <= A.length
	A[i] is 0 or 1
*/

class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int res = 0;
		int cur = 0;
		vector<int> temp;
		temp.push_back(0);
		for (int i = 0; i < A.size(); i++) {
			if (K > 0) {
				if (A[i] == 1) {
					temp[temp.size() - 1]++;
					cur++;
					res = max(res, cur);
					continue;
				}
				if (A[i] == 0) {
					temp[temp.size() - 1]++;
					temp.push_back(0);
					K--;
					cur++;
					res = max(res, cur);
					continue;
				}
			}
			if (K == 0) {
				if (A[i] == 1) {
					temp[temp.size() - 1]++;
					cur++;
					res = max(res, cur);
					continue;
				}
				if (A[i] == 0) {
					temp[temp.size() - 1]++;
					temp.push_back(0);
					cur = cur + 1 - temp[0];
					temp.erase(temp.begin());
					res = max(res, cur);
					continue;
				}
			}
		}
		return res;
	}
};
