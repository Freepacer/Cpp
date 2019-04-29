/*
Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.
Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

Example 1:
	Input: [1,17,8]
	Output: 2
	Explanation:
	[1,8,17] and [17,8,1] are the valid permutations.

Example 2:
	Input: [2,2,2]
	Output: 1

Note:
	1 <= A.length <= 12
	0 <= A[i] <= 1e9
*/

class Solution {
public:
	int numSquarefulPerms(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		pmt(nums, 0, ans);
		return ans.size();
	}
	void pmt(vector<int> nums, int idx, vector<vector<int>>& ans) {
		if (idx >= nums.size()) {
			ans.push_back(nums);
		}
		for (int i = idx; i < nums.size(); i++) {
			if (i > idx && nums[i] == nums[idx]) continue;
			swap(nums[i], nums[idx]);
			if (idx > 0) {
				if (sat(nums[idx] + nums[idx - 1])) {
					pmt(nums, idx + 1, ans);
				}
			}
			else
				pmt(nums, idx + 1, ans);
		}
	}
	bool sat(int v) {
		int r = sqrt(v);
		return r * r == v;
	}
};
