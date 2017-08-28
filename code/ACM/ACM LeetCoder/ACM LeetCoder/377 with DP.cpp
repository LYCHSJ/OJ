#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		vector<int> dp(target + 1, 0);
		for (int i = 1; i <= target; i++) {
			int count = 0;
			for (int j = 0; j < nums.size(); j++) {
				if (i < nums[j]) break;
				if (i == nums[j]) count++;
				else count += dp[i - nums[j]];
			}
			dp[i] = count;
		}
		return dp[target];
	}
};
int main() {
	Solution s;

}