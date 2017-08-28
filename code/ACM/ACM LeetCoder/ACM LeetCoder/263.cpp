#include<iostream>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num == 0)return false;
		while (!(num % 5)) {
			num /= 5;
		}
		while (!(num % 3)) {
			num /= 3;
		}
		while (!(num % 2)) {
			num /= 2;
		}
		if (num ^ 1)return false;
		else return true;
	}
};
int main() {
	Solution s;
	int x = 60;
	cout << s.isUgly(x) << endl;
	return 0;
}