#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<int> orderstr= extractstr(str);
		if (orderstr.size() != pattern.size())return false;
		vector<int> orderPattern = extractPattern(pattern);
		if (orderPattern != orderstr)return false;
		return true;
	}
	vector<int> extractPattern(string pattern) {
		vector<int> order;
		vector<char>characters;
		char character;
		int x = 0;
		for(int i = 0; i < pattern.size(); i++) {
			vector<char>::iterator result = find(characters.begin(), characters.end(), pattern[i]);
			x = characters.size();
			if (result == characters.end()) {
				characters.push_back(pattern[i]);
			}
			else {
				x = result - characters.begin();
			}
			order.push_back(x);
		}
		return order;
	}
	vector<int> extractstr(string str) {
		istringstream line(str);
		string word;
		int x = 0;
		vector<string>pharse;
		vector<int> order;
		while (line >> word) {
			vector<string>::iterator result = find(pharse.begin(), pharse.end(), word);
			x = pharse.size();
			if (result == pharse.end()) {
				pharse.push_back(word);
			}
			else {
				x = result - pharse.begin();
			}
			order.push_back(x);
		}
		return order;
	}
};
/*
bool wordPattern(string pattern, string str) {
map<char, int> p2i;
map<string, int> w2i;
istringstream in(str);
int i = 0, n = pattern.size();
for (string word; in >> word; ++i) {
if (i == n || p2i[pattern[i]] != w2i[word])
return false;
p2i[pattern[i]] = w2i[word] = i + 1;
}
return i == n;
}
*/
int main() {
	Solution s;
	string pattern = "ABBBC";
	string str = "cat dog dog cat fox";
	cout << s.wordPattern(pattern,str) << endl;
	return 0;
}