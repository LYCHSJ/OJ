#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string toHex(int num) {
		unsigned int n = num;
		string ret = "";
		if (n == 0)ret = "0";
		while (n) {
			int tmp = n % 16;
			if(tmp<10)ret = char(tmp + 48)+ret;
			else ret = char(tmp + 87)+ret;
			n /= 16;
		}
		return ret;
	}
};
int main() {
	Solution s;
	int num = -2;
	cout << s.toHex(num) << endl;
	return 0;
}