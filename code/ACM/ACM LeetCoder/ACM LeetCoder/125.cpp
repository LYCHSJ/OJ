#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty())return true;
		string text = "";
		for (int i = 0; i < s.size(); i++) {
			text = (s[i]>64 && s[i]<91)||(s[i]>96 && s[i]<123 ||s[i]>47 && s[i]<58)? text+s[i]:text;
		}
		cout << text << endl;
		int left = 0;
		int right = text.size() - 1;
		while (left < right) {
			if (text[left]>47 && text[left] < 58) {
				if (text[left] ^ text[right])return false;
			}
			else if ((0x1F & text[left]) ^ (0x1F & text[right]))return false;
			left++;
			right--;
		}
		return true;
	}
};

int main() {
	Solution s;
	string str = "A man, a plan, a canal: Panama";
	cout << s.isPalindrome(str) << endl;
	return 0;
}