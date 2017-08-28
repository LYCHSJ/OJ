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
	TreeNode* invertTree(TreeNode* root) {
		TreeNode * listnode = root;
		TreeNode * tmp;
		if (!listnode)return NULL;
		tmp = invertTree(listnode->left);
		listnode->left = invertTree(listnode->right);
		listnode->right = tmp;
		return listnode;
	}
};
