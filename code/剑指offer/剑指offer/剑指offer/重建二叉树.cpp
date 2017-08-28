#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())return NULL;
		int length = pre.size();
		return ConstructCore(0, length - 1, 0, length - 1, pre, vin);
	}
	TreeNode* ConstructCore(int prestart, int preend, int instart, int inend, vector<int> pre, vector<int> vin) {
		int root_v = pre[prestart];
		TreeNode * root = new TreeNode(root_v);
		if (prestart == preend) {
			if (instart == inend&&prestart == instart) {
				return root;
			}
		}
		int rootInorder = instart;
		for (rootInorder; rootInorder <= inend; rootInorder++) {
			if (vin[rootInorder] == root_v)break;
		}
		int leftlength = rootInorder - instart;
		int leftpreend = prestart + leftlength;
		if (leftlength > 0) {
			root->left = ConstructCore(prestart + 1, leftpreend, instart, rootInorder - 1, pre, vin);
		}
		if (leftlength < preend - prestart) {
			root->right = ConstructCore(leftpreend + 1, preend, rootInorder + 1, inend, pre, vin);
		}
		return root;
	}
};