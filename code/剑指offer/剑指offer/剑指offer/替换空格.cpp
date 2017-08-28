#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		string word = str;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == ' ')word.replace(i, 1, "%20");
		}
		char * str1="";
		for (int i = 0; i < word.size(); i++) {
			str1[i] = word[i];
		}
		str = str1;
	}
};
int main() {
	Solution s;
	char *str = "we are happy";
	int length = strlen(str);
	s.replaceSpace(str, length);
	string word = str;
	cout << word << endl;
	return 0;
}