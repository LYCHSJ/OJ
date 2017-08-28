#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		stack<int > v;
		v.push(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			if (v.top() != nums[i])v.pop();
			else v.push(nums[i]);
			if (v.empty())v.push(nums[i]);
		}
		return v.top();
	}
};



int main() {
	Solution s;
	vector<int> nums = {2,2,1,1,1,2,2};
	cout << s.majorityElement(nums) << endl;
	return 0;
}