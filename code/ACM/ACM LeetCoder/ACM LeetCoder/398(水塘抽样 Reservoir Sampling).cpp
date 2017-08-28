#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
class Solution {
	vector<int> nums;

public:
	Solution(vector<int> nums) {
		this->nums = nums;
		srand(time(NULL));
	}

	int pick(int target) {
		int result = 0, counter = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				if (rand() % counter == 0)result = i;
				counter++;
			}
		}
		return result;
	}
};