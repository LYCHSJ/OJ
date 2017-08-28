#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//if (1 == nums.size() && nums[0] == target)return 1;
		//if (1 == nums.size() && nums[0] != target)return 0;
		int low = 0;
		int high = nums.size()-1;
		while (low <= high) {
			int mid = (low + high) / 2;
			//if (target == nums[mid])return mid + 1;
			if (target > nums[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return low;//下界，求上界则条件改为return high
	}
};
int main() {
	Solution s;
	vector<int> v = { 1,3,5,6 };
	int x = 0;
	cout << s.searchInsert(v, x) << endl;
	return 0;
}
