#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int internal = 1;
		for (internal = 1; internal <nums.size(); internal++) {
			for (int j = 0; j < (nums.size()-internal);j++){
				if ((nums[j+internal] + nums[j]) == target) {
					vector<int> result = {j,j+internal};
					return result;
				}

			}
		}
	}
};
int main() {
	Solution s;
	vector<int> nums= { 3,2,4 };
	int target = 6;
	vector<int> result = s.twoSum(nums, target);
	cout << result[0] << " " << result[1] << endl;
	
}