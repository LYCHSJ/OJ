#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string res;
		int i = a.size(), j = b.size(), cur = 0;
		while (i || j || cur) {
			cur += (i ? a[(i--) - 1] - '0' : 0) + (j ? b[(j--) - 1] - '0' : 0);
			res = char(cur % 2 + '0') + res;
			cur /= 2;
		}
		return res;
	}
};
int main() {
	Solution s;
	string a = "1";
	string b = "11";
	cout << s.addBinary(a, b) << endl;
	return 0;
}