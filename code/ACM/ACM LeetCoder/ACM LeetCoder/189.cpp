#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		Reverse(nums, 0, nums.size()-1);
		Reverse(nums, 0, k - 1);
		Reverse(nums, k, nums.size() - 1);
	}
	void Reverse(vector<int> & nums, int L, int R) {
		int tmp;
		for (; L<R; L++,R--) {
			tmp = nums[L];
			nums[L] = nums[R];
			nums[R] = tmp;
		}
	}
};

int main() {
	Solution s;
	vector<int >nums = { 1,2,3,4,5,6,7 };
	s.rotate(nums, 3);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	cout << endl;
}