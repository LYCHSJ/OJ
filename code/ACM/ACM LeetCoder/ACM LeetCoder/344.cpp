#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string newword;
		if (s.empty())return newword;
		for (int i = s.size() - 1; i >= 0; i--) {
			newword += s[i];
		}
		return newword;
	}
};
int main(){
	string word = "Hello";
	Solution s;
	cout << s.reverseString(word) << endl;
}