#include<iostream>
#include<String>
#include<vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())return 0;
		if (s.length() == 1)return 1;
		int n = s.length();
		vector<int> alllength(n);
		vector<string> Start(n);
		string sfront;
		string sback;
		sback = s[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			Start[i];
			//s[i]+Start[i]��ʾiλ�ÿ�ʼ���ַ�����s[i]��+"i+1"λ�ÿ�ʼ����Ӵ�Start[i+1]
			sfront = s[i];
			alllength[i]=maxlength(sfront + Start[i + 1], sback);//����alllength[i]����������Ӵ���

		}//����alllength[n]
		return alllength[0];
	}
	int maxlength(string str1, string str2) {
		if (str1.length() > str2.length()) {
			str2 = str1;
			return str1.length();
		}
		else return str2.length();
	}

};

int main() {
	string a = "abcabcbb";
	Solution s;
	int result = s.lengthOfLongestSubstring(a);
	cout << result << endl;
}