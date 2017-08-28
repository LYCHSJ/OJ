#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bitnum[32] = { 0 };
		int res = 0;
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < nums.size(); j++) {
				bitnum[i] += (nums[j] >> i) & 1;
			}
			res |= (bitnum[i]%3) << i;
		}
		return res;
	}
};
int main() {
	Solution s;
	vector<int> v = { 1 };
	cout << s.singleNumber(v) << endl;
	return 0;
}