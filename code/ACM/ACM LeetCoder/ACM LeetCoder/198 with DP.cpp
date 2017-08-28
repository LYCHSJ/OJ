#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int> &num) {
		int n = num.size();
		if (n == 0)
			return 0;
		else if (n == 1)
			return num[0];
		else
		{
			vector<int> maxV(n, 0);
			maxV[0] = num[0];
			maxV[1] = max(num[0], num[1]);
			for (int i = 2; i < n; i++)
				maxV[i] = max(maxV[i - 2] + num[i], maxV[i - 1]);
			return maxV[n - 1];
		}
	}
};