/*
We are given the root node of a maximum tree: a tree where every node has a value greater than any other value in its subtree.
Just as in the previous problem, the given tree was constructed from an list A (root = Construct(A)) recursively with the following Construct(A) routine:
	If A is empty, return null.
	Otherwise, let A[i] be the largest element of A.  Create a root node with value A[i].
	The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
	The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
	Return root.
Note that we were not given A directly, only a root node root = Construct(A).
Suppose B is a copy of A with the value val appended to it.  It is guaranteed that B has unique values.
Return Construct(B).

Example 1:
	Input: root = [4,1,3,null,null,2], val = 5
	Output: [5,4,null,1,3,null,null,2]
	Explanation: A = [1,4,2,3], B = [1,4,2,3,5]

Example 2:
	Input: root = [5,2,4,null,1], val = 3
	Output: [5,2,4,null,1,null,3]
	Explanation: A = [2,1,5,4], B = [2,1,5,4,3]

Example 3:
	Input: root = [5,2,3,null,1], val = 4
	Output: [5,2,4,null,1,3]
	Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
		
Note:
	1 <= B.length <= 100
*/


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		vector<int> temp;
		converttovector(root, temp);
		temp.push_back(val);
		TreeNode* res;
		if (temp.size() == 0) return res;
		res = new TreeNode(0);
		convertback(res, res, temp, 0, temp.size());
		return res;
	}

	void converttovector(TreeNode * root, vector<int> & res) {
		if (root == NULL) return;
		converttovector(root->left, res);
		res.push_back(root->val);
		converttovector(root->right, res);
		return;
	}

	void convertback(TreeNode * &res, TreeNode * cur, vector<int> & temp, int start, int end) {
		if (start == end) {
			return;
		}
		int pos = start;
		int curmax = INT_MIN;
		for (int i = start; i < end; i++) {
			if (temp[i] > curmax) {
				curmax = temp[i];
				pos = i;
			}
		}
		cur->val = temp[pos];
		if (start < pos)
		{
			cur->left = new TreeNode(0);
			convertback(res, cur->left, temp, start, pos);
		}
		if (pos != end - 1)
		{
			cur->right = new TreeNode(0);
			convertback(res, cur->right, temp, pos + 1, end);
		}

		return;
	}
};
