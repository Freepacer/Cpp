/*
	We run a preorder depth first search on the root of a binary tree.
	At each node in this traversal, we output D dashes(where D is the depth of this node), then we output the value of this node.  
	(If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.)
	If a node has only one child, that child is guaranteed to be the left child.
	Given the output S of this traversal, recover the treeand return its root.

Example 1:
	Input: "1-2--3--4-5--6--7"
	Output: [1,2,5,3,4,6,7]
Example 2:
	Input: "1-2--3---4-5--6---7"
	Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:
	Input: "1-401--349---90--88"
	Output: [1,401,null,349,88,90]

Note:
	The number of nodes in the original tree is between 1 and 1000.
	Each node will have a value between 1 and 1e9.
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
	TreeNode* recoverFromPreorder(string S) {
		if (S.empty()) return NULL;
		if (S[0] == '-') return NULL;
		int ind = 0;
		int growdep = -1;
		int temp = 0;
		TreeNode * head = new TreeNode(0);
		while (ind < S.size() && S[ind] != '-') {
			temp = temp * 10 + (S[ind] - '0');
			ind++;
		}
		head->val = temp;
		helper(head, S, ind, 1, growdep);
		helper(head, S, ind, 1, growdep);
		return head;
	}

	void helper(TreeNode * prenode, string & S, int& ind, int curdep, int& growdep) {
		if (growdep != -1 && growdep == curdep) {
			int temp = 0;
			while (ind < S.size() && S[ind] != '-') {
				temp = temp * 10 + (S[ind] - '0');
				ind++;
			}
			prenode->right = new TreeNode(temp);
			growdep = -1;
			helper(prenode->right, S, ind, curdep + 1, growdep);
			helper(prenode->right, S, ind, curdep + 1, growdep);
		}
		if (growdep != -1 && growdep != curdep) return;
		if (!prenode || ind == S.size()) return;
		growdep = 0;
		while (ind < S.size() && S[ind] == '-') {
			growdep++;
			ind++;
		}
		if (growdep == curdep)
		{
			int temp = 0;
			while (ind < S.size() && S[ind] != '-') {
				temp = temp * 10 + (S[ind] - '0');
				ind++;
			}
			prenode->left = new TreeNode(temp);
			growdep = -1;
			helper(prenode->left, S, ind, curdep + 1, growdep);
			helper(prenode->left, S, ind, curdep + 1, growdep);
		}
		return;
	}
};