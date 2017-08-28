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
	int kthSmallest(TreeNode* root, int k) {
		int num = 0;
		knum = k;
		countNumber(root, 1);
		return ret;
	}
	int countNumber(TreeNode* node,int count) {
		int tmp = count;
		int inside_tmp = tmp;
		if (node->left) {
			tmp = countNumber(node->left,inside_tmp)+1;
 			inside_tmp = tmp;
		}

		if (tmp == knum) {
			ret = node->val;
		}
		if (node->right) {
			inside_tmp = countNumber(node->right, inside_tmp+1);
		}
		return inside_tmp;
	}
private:
	int knum;
	int ret;
};
int main() {
	Solution s;
	TreeNode * node1 = new TreeNode(6);
	TreeNode * node2 = new TreeNode(3);
	TreeNode * node3 = new TreeNode(2);
	TreeNode * node4 = new TreeNode(1);
	TreeNode * node5 = new TreeNode(5);
	TreeNode * node6 = new TreeNode(7);
	node2->left = node3;
	node2->right = node1;
	node3->left = node4;
	node1->left = node5;
	node1->right = node6;
	cout << s.kthSmallest(node2, 6) << endl;
	return 0;
}