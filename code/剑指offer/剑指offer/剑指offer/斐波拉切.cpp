#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int Fibonacci(int n) {
		vector<int>f(n + 1, 0);
		f[1] = 1;
		f[2] = 1;
		for (int i = 3; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};