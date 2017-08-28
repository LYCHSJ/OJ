#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	int addDigits(int num) {
		return num == 0 ? 0 : (num - 1) % 9 + 1;
	}
};
int main() {
	Solution s;
	int num = 123;
	cout << s.addDigits(num) << endl;
	return 0;
}