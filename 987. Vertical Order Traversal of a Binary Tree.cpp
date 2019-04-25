/*
Given a binary tree, return the vertical order traversal of its nodes values.
For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, 
we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

Example 1:
	Input: [3,9,20,null,null,15,7]
	Output: [[9],[3,15],[20],[7]]
	Explanation:
	Without loss of generality, we can assume the root node is at position (0, 0):
	Then, the node with value 9 occurs at position (-1, -1);
	The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
	The node with value 20 occurs at position (1, -1);
	The node with value 7 occurs at position (2, -2).

Example 2:
	Input: [1,2,3,4,5,6,7]
	Output: [[4],[2],[1,5,6],[3],[7]]
	Explanation:
	The node with value 5 and the node with value 6 have the same position according to the given scheme.
	However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.

Note:
	The tree will have between 1 and 1000 nodes.
	Each node's value will be between 0 and 1000.
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
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<pair<int, int>, vector<int>> pos;
		helper(root, pos, 0, 0);
		vector<vector<int>> res;
		int para = INT_MAX;
		for (auto it = pos.begin(); it != pos.end(); it++) {
			if (para != (it->first).first) {
				vector<int> incre;
				res.push_back(incre);
				para = (it->first).first;
			}
			vector<int> tempit = it->second;
			sort(tempit.begin(), tempit.end());
			for (int i = 0; i < tempit.size(); i++) {
				res[res.size() - 1].push_back(tempit[i]);
			}
		}
		return res;
	}
	void helper(TreeNode* node, map<pair<int, int>, vector<int>>& pos, int vert, int para)
	{
		if (node == NULL) return;
		pair<int, int> tempair;
		tempair.first = para;
		tempair.second = vert;
		pos[tempair].push_back(node->val);
		helper(node->left, pos, vert + 1, para - 1);
		helper(node->right, pos, vert + 1, para + 1);
	}
};