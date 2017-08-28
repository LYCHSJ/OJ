#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		vector<vector<int>> results = {};
		if (nums.size()<3)return results;
		sort(nums.begin(), nums.end());

		int right;
		int tmp;
		int left=0;

		while (left <=nums.size()-3) {
			right = left + 1;
			int end = nums.size() - 1;
			while(right < end) {
					if ((nums[end] + nums[right] + (nums[left]))==0) {
						vector<int> result = { nums[left],nums[right],nums[end]};
						results.push_back(result);
						tmp = nums[end]; while (end >= right && nums[end] == tmp)end--;
					}
					
					if ((nums[end] + nums[right] + (nums[left]))<0) { tmp = nums[right]; while (right <= end && nums[right] == tmp)right++; }
					
					if((nums[end] + nums[right] + (nums[left]))>0){tmp = nums[end]; while (end >= right && nums[end] == tmp)end--; }

			}
		
			tmp = nums[left];
			while(left <=nums.size()-1 && nums[left]==tmp)left++;
		}

		return results;
	}
};
int main() {
	Solution s;
	vector<int> nums = { -2,10,-14,11,5,-4,2,0,-10,-10,5,7,-11,10,-2,-5,2,12,-5,14,-11,-15,-5,12,0,13,8,7,10,6,-9,-15,1,14,11,-9,-13,-10,6,-8,-5,-11,6,-9,14,11,-7,-6,8,3,-7,5,-5,3,2,10,-6,-12,3,11,1,1,12,10,-8,0,8,-5,6,-8,-6,8,-12,-14,7,9,12,-15,-12,-2,-4,-4,-12,6,7,-3,-6,-14,-8,4,4,9,-10,-7,-4,-3,1,11,-1,-8,-12,9,7,-9,10,-1,-14,-1,-8,11,12,-5,-7};
	vector<vector<int>> results=s.threeSum(nums);
	for (int i = 0; i < results.size(); i++) {
		cout << nums[results[i][0]] << " " << nums[results[i][1]] << " " << nums[results[i][2]] << endl;
	}
	return 0;
}