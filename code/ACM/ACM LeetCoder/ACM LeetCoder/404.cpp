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
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)return 0;
		if (!(root->left || root->right))return 0;

		int ret = sumof(root);
		return ret;
		
	}
	int sumof(TreeNode * node) {
		int ret = 0;
		if(node->left)ret += sumof(node->left);
		if(node->right)ret += sumof(node->right);
		if (node->left &&!(node->left->left || node->left->right)) ret += node->left->val;
		return ret;
	}
};
int main() {
	TreeNode * root = new TreeNode(3);
	TreeNode * node1 = new TreeNode(9);
	TreeNode * node2 = new TreeNode(20);
	TreeNode * node3 = new TreeNode(15);
	TreeNode * node4 = new TreeNode(7);
	root->left = node1;
	root->right = node2;
	node2->left = node3;
	node2->right = node4;
	Solution s;
	cout << s.sumOfLeftLeaves(root) << endl;
}

