#include<iostream>
using namespace std;
class Solution {
public:
	bool isPowerOfFour(int num) {
		return (num > 0) && ((num&(num - 1)) == 0) && (num & 0x55555555);
	}
};
int main() {
	int x = 256;
	Solution s;
	cout << s.isPowerOfFour(x) << endl;
	return 0;
}