#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		TreeNode *node = root;
		if (!root)return ret;
		while (!(node->left || node->right)) {

			if (node = node->left) {
				node = node->left;
				continue;
			}
			node->val;
		}
	}
	vector<int> goThrough(TreeNode* node) {
		vector<int> ret;
		ret.push_back(node->val);
		if (!(node->left || node->right))return ret;
	}
	vector<string> inttostring(vector<vector<int>> v) {
		vector<string> ret(v.size(),"");
		for (int i = 0; i < ret.size(); i++) {
			string str;
			for (int j = 0; j < v[i].size() - 1; j++) {
				str = char(v[i][j] + 30) + "->";
			}
			str += char(v[i][ret[i].size() - 1] + 30);
			ret[i] = str;
		}
		return ret;
	}
};

int main() {

}