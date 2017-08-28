#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)return "";
		int len = strs[0].size();
		int j = 0;
		for (; j < len; j++) {
			for (int i = 1; i < strs.size(); i++) {
				if (strs[i][j] != strs[i - 1][j]) {
					len = j; break;
				}
			}
		}
		return strs[0].substr(0, len);
	}
};

int main() {
	Solution s;
	vector<string> strs = { "ab","abc","abc" };
	cout<<s.longestCommonPrefix(strs)<<endl;
	return 0;
}