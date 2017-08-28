#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int result=-1;
		if (needle.empty())return 0;
		if (haystack.empty())return result;
		char * p=&haystack[0];
		char * n = &needle[0];
		for (int i = 0; i < haystack.size(); i++) {
			if(strncmp(n, p, needle.size())==0)return result=i;
			p++;
		}
		return result;
	}
};
int main() {
	Solution s;
	string haystack = "asdfgghhj";
	string needle = "asd";
	cout<<s.strStr(haystack, needle)<<endl;
	return 0;
}