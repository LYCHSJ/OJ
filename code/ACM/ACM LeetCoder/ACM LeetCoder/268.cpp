#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int max = -1;
		int ret = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > max)max = nums[i];
		}
		vector<int> v(max + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			v[nums[i]] = 1;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0)ret = i;
		}
		if (ret == -1)ret = max + 1;
		return ret;
	}
};