#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		stringstream buffer;
		string str = "";
		int i = 0;
		int num = 1;
		int index = n;
		while (n > 0) {
			buffer << num;
			str += buffer.str().c_str();
			n -= buffer.str().size();
			buffer.str("");
			i++;
			num++;
		}
		int ret = int(char(str[index-1])) - 48;
		return ret;
	}
};

int main() {
	Solution s;
	int x = 100;
	cout << s.findNthDigit(x) << endl;
	return 0;
}