#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			while (!isalnum(s[i]) && i < j) i++;
			while (!isalnum(s[j]) && i < j) j--;
			if (tolower(s[i++]) != tolower(s[j--]))
				return false;
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