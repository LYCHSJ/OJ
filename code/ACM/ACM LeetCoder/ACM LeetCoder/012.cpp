#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		vector<vector<string> > v = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }
		};
		string ret = "";
		int digit = 0;
		while (num != 0) {
			int remain = num % 10;
			ret = v[digit][remain] + ret;
			digit++;
			num /= 10;
		}

		return ret;
	}
};
int main() {
	Solution s;
	int x = 54;
	cout << s.intToRoman(x) << endl;
	return 0;
}