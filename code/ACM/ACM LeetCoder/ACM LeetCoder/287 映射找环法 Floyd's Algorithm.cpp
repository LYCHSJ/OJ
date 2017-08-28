#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int> nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast) {
			slow=nums[slow];
			fast=nums[nums[fast]];
		}
		fast = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
};
int main() {
	vector<int > nums = { 1,2,2,5,6,7,8,9,11 };
	Solution s;
	cout << s.findDuplicate(nums) << endl;
	return 0;
}