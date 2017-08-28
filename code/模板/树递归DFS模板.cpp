#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void tree_func(TreeNode * root) {
	if (!root)return;
	if(!root->left&&!root->right){}//р╤вс╫А╣Ц
	if (root->left) {
		tree_func(root->left);
	}
	if (root->right) {
		tree_func(root->right);
	}
}