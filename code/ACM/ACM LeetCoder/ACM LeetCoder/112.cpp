#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)return false;
		vector<int > v = goThrough(root);
		if (find(v.begin(), v.end(), sum) != v.end())return true;
		else return false;
	}
	vector<int> goThrough(TreeNode * node) {
		vector<int> lv; vector<int> rv;
		if (node->left)lv = goThrough(node->left);
		if (node->right)rv = goThrough(node->right);
		lv.insert(lv.end(), rv.begin(), rv.end());
		for (int i = 0; i < lv.size();i++) {
			lv[i]+= node->val;
		}
		if (!(node->left || node->right))lv.push_back(node->val);
		return lv;
	}
};

int main() {
	TreeNode * node1 = new TreeNode(-1);
	TreeNode * node2 = new TreeNode(-2);
	node1->left = node2;
	Solution s;
	cout << s.hasPathSum(node1, -3) << endl;
	return 0;
}