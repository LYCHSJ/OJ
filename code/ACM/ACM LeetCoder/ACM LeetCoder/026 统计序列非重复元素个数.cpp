#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())return 0;
		int flag=nums[0];
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[count] < nums[i]) {
				nums[++count] = nums[i];
			}
		}
		return count+1;
	}
};

int main() {
	vector<int> nums = { 2,2,3,5,6,6,7 };
	Solution s;
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}