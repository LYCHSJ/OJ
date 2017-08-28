#include<iostream>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)return false;
		int judge = 1;
		while (judge < n) {
			if ((judge&n))return false;
			judge <<= 1;
		}
		return true;
	}
};
int main() {
	Solution s;
	int n = 10;
	cout << s.isPowerOfTwo(n) << endl;
	return 0;
}