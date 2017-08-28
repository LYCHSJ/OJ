#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		string count = "";
		int nCount=0;
		string ret = "";
		int fore;
		int back;
		string tmp = "";
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 93) {
				stringstream ssCount(count);
				ssCount >> nCount;
				for (int j = 0; j < nCount; j++) {
					ret.append(tmp);
				}
				s.replace(fore-1, back - fore + 2, ret);
				tmp = "";
				count = "";
				nCount = 0;
				ret = "";
				back = i;
			}
			if (s[i] == 91) {
				fore = i;
				tmp.insert(0, s, fore, back - fore + 1);
			}
			if (s[i] > 47 && s[i] < 58) {
				count = s[i]+count;
			}
		}
		for (int j = 0; j < nCount; j++) {
			ret.append(tmp);
		}
		s.replace(fore - 1, back - fore + 2, ret);
		return s;		
	}
};
int main() {
	Solution s;
	string str = "3[a2[c]]";
	cout << s.decodeString(str) << endl;
	return 0;
}