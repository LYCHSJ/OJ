#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int index = 0;
		int k = 0;
		bool flag=false;
		for (k; k < s.size(); k++) {
			flag = false;
			for (int i = index; i < t.size(); i++) {
				if (t[i] == s[k]) {
					index = i + 1;
					flag = true;
					break;
				}
			}
			if (!flag)return false;
		}
		return true;	
	}
};
int main() {
	Solution so;
	string s = "abc";
	string t = "ab";
	cout << so.isSubsequence(s, t) << endl;
	return 0;
}