#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> v(26, 0);
		for (int i = 0; i < s.size(); i++) {
			v[int(s[i]) - 97] += 1;
		}
		for (int i = 0; i < t.size(); i++) {
			v[int(t[i]) - 97] -= 1;
			if (v[int(t[i]) - 97] < 0)return t[i];
		}
		return s[0];
	}
};
int main() {
	Solution solution;
	string s = "abcd";
	string t = "abcde";
	cout << solution.findTheDifference(s, t) << endl;
	return 0;
}