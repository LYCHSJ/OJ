#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int n = s.length();
		int counts[26] = { 0 };
		for (int i = 0; i < n; i++) {
			counts[s[i] - 'a']++;
			counts[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (counts[i]) return false;
		return true;
	}
};

int main() {
	string s = "qwerreetr";
	string t = "qwerqttwer";
	Solution fun;
	cout << fun.isAnagram(s, t) << endl;

}