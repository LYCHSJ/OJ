#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if ((p->val - root->val)*(q->val - root->val) <= 0)return root;
		if (p->val > root->val) {
			root = root->right;
			return lowestCommonAncestor(root, p, q);
		}
		else {
			root = root->left;
			return lowestCommonAncestor(root, p, q);
		}
	}
};