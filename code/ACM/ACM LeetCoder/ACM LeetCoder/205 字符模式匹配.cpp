#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int a[256];
		int b[256];
		if (s.size() != t.size())return false;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < s.size(); i++) {
			if (a[s[i]] == 0 && b[t[i]] == 0) {//²åÈëÌõ¼þ
				a[s[i]] = t[i];
				b[t[i]] = s[i];
			}
			else if (a[s[i]] == t[i] && b[t[i]] == s[i]){
				continue;
			}
			else return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	string str1 = "ab";
	string str2 = "aa";
	cout << s.isIsomorphic(str1, str2) << endl;
	return 0;
}