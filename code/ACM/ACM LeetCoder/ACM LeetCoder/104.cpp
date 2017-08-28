#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root)return 0;
		return max = goThrough(root);
	}
	int goThrough(TreeNode * node) {
		int ldeepth = 0;
		int rdeepth = 0;
		TreeNode * lChild;
		TreeNode * rChild;
		if (node->left) {
			lChild = node->left;
			ldeepth =goThrough(lChild);

		}
		if (node->right) {
			rChild = node->right;
			rdeepth = goThrough(rChild);

		}
		int deepth = ldeepth > rdeepth ? ldeepth : rdeepth;
		deepth++;
		return deepth;
	}
private:
	int max = 0;
};