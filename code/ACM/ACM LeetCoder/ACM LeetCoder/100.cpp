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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return p == NULL || q == NULL ? p == q : p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
int main() {
	TreeNode * node1 = new TreeNode(0);
	TreeNode * node2 = new TreeNode(1);
	TreeNode * node3 = new TreeNode(2);
	TreeNode * node7 = new TreeNode(3);
	node1->left = node2;
	node1->right = node3;
	node2->right = node7;
	TreeNode * node4 = new TreeNode(0);
	TreeNode * node5 = new TreeNode(1);
	TreeNode * node6 = new TreeNode(2);
	TreeNode * node8 = new TreeNode(3);
	node4->left = node5;
	node4->right = node6;
	node5->right = node8;
	Solution s;
	cout << s.isSameTree(node1, node4) << endl;
	return 0;
}