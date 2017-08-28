#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0;
		for (int i = 1; i < prices.size(); i++) {
			int raise = prices[i] - prices[i - 1];
			if (raise > 0) {
				ret += raise;
			}
		}
		return ret;
	}
};
int main() {
	vector<int > v = { 5,3,6,7,3,6,1,9 };
	Solution s;
	cout << s.maxProfit(v) << endl;
	return 0;
}