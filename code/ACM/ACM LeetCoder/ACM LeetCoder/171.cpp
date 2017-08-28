#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		int titlenumber = 0;
		for (int i = 0; i < s.size(); i++) {
			titlenumber *= 26;
			titlenumber += (int(s[i]) - 64);
		}
		return titlenumber;
	}
};
int main() {
	Solution s;
	string str = "A";
	cout << s.titleToNumber(str) << endl;
	return 0;
}