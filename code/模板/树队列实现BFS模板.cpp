#include<queue>
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//BFS
void tree_func(TreeNode * root) {
	if (!root)return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *cur = q.front();
		//结点相应处理//
		if (cur->left) {
			q.push(cur->left);
		}
		if (cur->right) {
			q.push(cur->right);
		}
		q.pop();
	}
}
//BFS分层
void tree_func(TreeNode * root) {
	if (!root)return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q.size(); i++) {
			TreeNode *cur = q.front();
			//结点相应处理//
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
			q.pop();
		}
	}
}