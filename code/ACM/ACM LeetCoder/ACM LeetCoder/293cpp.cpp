#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.empty())return;
		int count = 0;
		vector<int >::iterator it = nums.begin();
		while( it != nums.end()) {
			if (!(*it ^ 0)) {
				if (it == nums.end() - 1) {
					 break;
				}
				it = nums.erase(it);
				count++;
			}
			else it++;
		}
		for (int i = 0; i < count; i++) {
			nums.push_back(0);
		}
	}
};

int main() {
	Solution s;
	vector<int > nums = { 0,0,1 };
	s.moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	cout << endl;
	return 0;
}