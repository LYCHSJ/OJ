#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0)return 1;
		vector<int> v(n,0);
		v[0]=10;
		for (int i = 1; i < n; i++) {
			v[i] = multiple(i) + v[i - 1];
		}
		return v[n - 1];
	}
	int multiple(int num) {
		int ret = 1;
		for (int i = 0; i < num+1;i++ ) {
			ret *= (10 - i);
		}
		ret = ret / 10 * 9;
		return ret;
	}
};
int main() {
	Solution s;
	int x = 3;
	cout << s.countNumbersWithUniqueDigits(x) << endl;
	return 0;
}