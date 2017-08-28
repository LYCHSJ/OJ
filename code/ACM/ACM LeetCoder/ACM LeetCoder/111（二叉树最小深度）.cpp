#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)return 0;
		int deepth = 1;
		if (!(root->left||root->right))return 1;
		return deepth += (root->left&&root->right) ? min(minDepth(root->left), minDepth(root->right)) : (root->left ? minDepth(root->left) : minDepth(root->right));
		//if(root->left&&root->right)deepth += min(minDepth(root->left), minDepth(root->right));
		//else deepth += root->left ? minDepth(root->left) : minDepth(root->right);
		//return deepth;
	}
};
int main() {
	TreeNode * root = new TreeNode(0);
	TreeNode * node1 = new TreeNode(1);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	root->left = node1;
	root->right = node2;
	node2->left = node3;
	Solution s;
	cout << s.minDepth(root) << endl;
}