/*
In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  
(A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the i-th domino, so that A[i] and B[i] swap values.
Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
If it cannot be done, return -1.

Example 1:
	Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
	Output: 2
	Explanation:
	The first figure represents the dominoes as given by A and B: before we do any rotations.
	If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:
	Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
	Output: -1
	Explanation:
	In this case, it is not possible to rotate the dominoes to make one row of values equal.


Note:
	1 <= A[i], B[i] <= 6
	2 <= A.length == B.length <= 20000
*/

class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		int num1 = 0;
		int num2 = 0;
		int times1 = 0;
		int times2 = 0;
		if (A.empty()) return -1;
		if (A.size() != B.size()) return -1;
		if (A.size() == 1) return 0;
		num1 = A[0];
		num2 = B[0];
		times2 = 1;
		int length = A.size();
		if (A[0] == B[0]) length--;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] == B[i]) length--;
			if (A[i] == num1) {
				if (B[i] == num2) {
					times2++;
					continue;
				}
				else
				{
					num2 = 0;
					continue;
				}
			}
			if (B[i] == num1) {
				times1++;
				if (A[i] == num2)
					continue;
				else
				{
					num2 = 0;
					continue;
				}
			}
			if (A[i] != num1 && B[i] != num1)
			{
				num1 = 0;
				if (A[i] == num2)
					continue;
				if (B[i] == num2) {
					times2++;
					continue;
				}
				else {
					num2 = 0;
					continue;
				}
			}
			if (num1 == 0 && num2 == 0)
				return -1;
		}
		if (num1 != 0 && num2 == 0) {
			return (times1 > length / 2) ? (length - times1) : times1;
		}
		if (num2 != 0 && num1 == 0) {
			return (times2 > length / 2) ? (length - times2) : times2;
		}
		if (num1 != 0 && num2 != 0) {
			return (times2 > times1) ? times1 : times2;
		}
		return -1;
	}
};
