#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> ret(n, 0);
		ret[0] = 1;
		ret[1] = 2;
		for(int i = 2; i < n; i++) {
			ret[i] = ret[i - 1] + ret[i - 2];
		}
		return ret[n-1];
	}
};

int main() {
	Solution s;
	int n = 44;
	cout << s.climbStairs(n) << endl;
	return 0;
}