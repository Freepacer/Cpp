/*
Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  
(The move may be from parent to child, or from child to parent.)
Return the number of moves required to make every node have exactly one coin.

Example 1:
	Input: [3,0,0]
	Output: 2
	Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.

Example 2:
	Input: [0,3,0]
	Output: 3
	Explanation: From the left child of the root, we move two coins to the root [taking two moves].  
	Then, we move one coin from the root of the tree to the right child.

Example 3:
	Input: [1,0,2]
	Output: 2

Example 4:
	Input: [1,0,0,null,3]
	Output: 4

Note:
	1<= N <= 100
	0 <= node.val <= N
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
	int distributeCoins(TreeNode* root) {
		map <TreeNode*, int> num;
		map <TreeNode*, int> dig;
		record(num, root);
		geshu(dig, root);
		return helper(num, dig, root);
	}

	int record(map <TreeNode*, int>& num, TreeNode* root) {
		if (!root) return 0;
		if (!num.count(root))
		{
			int n = root->val + record(num, root->left) + record(num, root->right);
			num[root] = n;
		}
		return num[root];
	}

	int geshu(map <TreeNode*, int>& dig, TreeNode* root) {
		if (!root) return 0;
		if (!dig.count(root))
		{
			int n = 0;
			n = 1 + geshu(dig, root->left) + geshu(dig, root->right);
			dig[root] = n;
		}
		return dig[root];
	}

	int cnt(map <TreeNode*, int>& num, map <TreeNode*, int>& dig, TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 0;
		if (root->left && root->right)
			return abs(num[root->left] - dig[root->left]) + abs(num[root->right] - dig[root->right]);
		if (root->left)
			return abs(num[root->left] - dig[root->left]);
		return abs(num[root->right] - dig[root->right]);
	}

	int helper(map <TreeNode*, int> & num, map <TreeNode*, int> & dig, TreeNode * root) {
		if (!root) return 0;
		return cnt(num, dig, root) + helper(num, dig, root->left) + helper(num, dig, root->right);
	}
};

