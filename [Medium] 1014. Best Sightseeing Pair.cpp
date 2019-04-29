/*
Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, 
and two sightseeing spots i and j have distance j - i between them.
The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : the sum of the values of the sightseeing spots, 
minus the distance between them.
Return the maximum score of a pair of sightseeing spots.

Example 1:
	Input: [8,1,5,2,6]
	Output: 11
	Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11

Note:
	2 <= A.length <= 50000
	1 <= A[i] <= 1000
*/

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		if (A.size() < 2) return 0;
		int res = A[0] + A[1] - 1;
		int first = 0;
		int second = 0;
		if (A[0] > A[1] + 1) first = 0;
		else first = 1;
		for (int i = 2; i < A.size(); i++) {
			if (A[i] + A[first] + first - i > res) {
				res = A[i] + A[first] + first - i;
			}
			if (A[i] > A[first] + first - i)
				first = i;
		}

		return res;
	}
};
