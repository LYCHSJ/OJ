#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int repr[1000];
		memset(repr, 0, sizeof(repr));
		if (n == 1)return true;
		while (n != 1) {
			n=cultivate(n);
			if (repr[n] == 1)return false;
			repr[n] = 1;
		}
		return true;
	}
	int cultivate(int n ) {
		int ans = 0;
		while (n) {
			ans += pow(n % 10,2);
			n /= 10;
		}
		return ans;
	}
};

int main() {
	int n = 11;
	Solution s;
	cout << s.isHappy(n) << endl;
	return 0;
}