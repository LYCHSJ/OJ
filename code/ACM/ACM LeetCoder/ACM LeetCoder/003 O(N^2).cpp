#include<iostream>
#include<String>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxlength=0;
		vector<int> dict(256, -1);
		int start=-1;
		for (int i = 0; i < s.size(); i++) {
			if (dict[s[i]] >start) {
				start = dict[s[i]];
			}
			dict[s[i]] = i;
			maxlength = max(maxlength, i - start);
		}
		return maxlength;
	}
};
int main() {
	string a = "aabc";
	Solution s;
	int result = s.lengthOfLongestSubstring(a);
	cout << result << endl;
}