#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())return 0;
		int min = prices[0];
		int max = 0;
		int res = 0;
		for (int i = 0; i<prices.size(); i++) {
			if (min>prices[i])min = prices[i];
			if (res<prices[i]-min)res = prices[i]-min;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2 };
	cout<<s.maxProfit(nums)<<endl;
	return 0;
}