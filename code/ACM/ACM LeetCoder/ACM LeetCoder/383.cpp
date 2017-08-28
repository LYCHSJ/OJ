#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		vector<int> v(26,0);
		for (int i = 0; i < magazine.size(); i++) {
			v[int(magazine[i]) - 97]++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			if(--v[int(ransomNote[i]) - 97]<0)return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	string str1 = "abb";
	string str2 = "aab";
	cout << s.canConstruct(str1, str2) << endl;
	return 0;
}