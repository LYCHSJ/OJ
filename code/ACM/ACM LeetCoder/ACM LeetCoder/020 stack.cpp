#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
class Solution {
	map<char, char> match{ pair<char,char>(')','('),pair<char,char>(']','['),pair<char,char>('}','{') };
public:
	bool isValid(string s) {
		if (s.empty())return true;
		stack<char> v;
		for (int i = 0; i < s.size(); i++) {
			if (!(s[i] ^ '(') || !(s[i] ^ '[') || !(s[i] ^ '{'))v.push(s[i]);
			if (!(s[i] ^ ')') || !(s[i] ^ ']') || !(s[i] ^ '}')) {	
				char x = match[s[i]];
				if (v.empty()||(v.top() ^ x))return false;
				v.pop();
			}
		}
		if (!v.empty())return false;
		return true;
	}
};
int main() {
	Solution s;
	string str = "[(hello)]";
	cout << s.isValid(str) << endl;
	return 0;
}