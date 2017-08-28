#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int integerBreak(int n) {
		if (n == 1)return 0;
		if (n == 2)return 1;
		if (n == 3)return 2;
		vector<int> v(n+1,0);
		v[0] = 1;
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		v[4] = 4;
		v[5] = 6;
		for (int i = 6; i < n + 1; i++) {
			int k = i - 3;
			int q = k / 3;
			int p = i % 3;
			v[i] = pow(v[3], q)*v[p+3];
		}
		return v[n];
	}
};
int main(){
	Solution s;
	int n = 11;
	cout << s.integerBreak(n) << endl;
	return 0;
}