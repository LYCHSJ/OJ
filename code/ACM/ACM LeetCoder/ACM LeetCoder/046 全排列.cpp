#include<iostream>
#include<vector>
using namespace std;
class Solution {
vector<vector<int> >vec;
public:
	void premi(vector<int>& nums,int k,int m) {
		vector<int> ret;
		if (k >= m) {
			for (int i = 0; i < nums.size(); i++) {
				ret.push_back(nums[i]);
			}
			vec.push_back(ret);
			return;
		}
		else {
			for (int i = k; i < m; i++) {
				swap(nums[i], nums[k]);
				premi(nums, k + 1, m);
				swap(nums[i], nums[k]);
			}
		}
		return;
	}
	vector<vector<int>> permute(vector<int>& nums) {
		premi(nums, 0, nums.size());
		return vec;
	}
};
int main() {
	Solution s;
	vector<int> nums = { 1,2,3 };
	s.permute(nums);
}