#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)return false;
		if (!root->left && !root->right)return true;
		bool flag = middleTraversal(root);
		return flag;
	}
	bool middleTraversal(TreeNode * root) {
		bool flag = true;

		queue<TreeNode *> q;
		q.push(root);
		TreeNode * min=new TreeNode(INT32_MIN);
		bool empty = false;
		while (!q.empty()) {

			int l = q.size();
			vector<int> curlayer;
			for (int i = 0; i < l; i++) {
				TreeNode *cur = q.front();
				q.pop();
				curlayer.push_back(cur->val);
				if (cur->left != NULL) q.push(cur->left);
				else q.push(min);
				if (cur->right != NULL) q.push(cur->right);
				else q.push(min);
			}
			for (int i = 0; i <curlayer.size()/2; i++) {
				if (curlayer[i] != curlayer[curlayer.size() - 1])return flag= false;
				if (curlayer[i] != INT32_MIN)empty = false;
			}
			if (empty)return true;
			empty = true;
			curlayer.clear();
		}
		return flag;
	}
};
int main() {
	TreeNode * root = new TreeNode(1);
	TreeNode * node1 = new TreeNode(2);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node3 = new TreeNode(3);
	TreeNode * node4 = new TreeNode(3);
	TreeNode * node5 = new TreeNode(4);
	TreeNode * node6 = new TreeNode(4);
	root->left = node1;
	root->right = node2;
	node1->left = node3;
	//node2->right = node5;
	//node1->right = node6;
	node2->left = node4;
	Solution s;
	cout << s.isSymmetric(root) << endl;
}