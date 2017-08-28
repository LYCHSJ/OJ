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
	vector<vector<int>> levelOrder(TreeNode* root) {
		TreeNode * node = root;
		int deepth = 0;
		if (!root)return result;
		vector<int> v;
		result.push_back(v);
		goThrough(node, 0);
		return result;
	}
	void goThrough(TreeNode * node,int deepth) {
		result[deepth].push_back(node->val);
		vector<int> v;
		if(deepth+2>result.size() &&(node->left||node->right))result.push_back(v);
		if (node->left) {
			int ldeepth=deepth+1;
			goThrough(node->left, ldeepth);
		}
		if (node->right) {
			int rdeepth = deepth + 1;
			goThrough(node->right, rdeepth);
		}
	}
private:
	vector<vector<int> > result;
};