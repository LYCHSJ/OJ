#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int aXORb = 0;
		for (int i = 0; i < nums.size(); i++) {
			aXORb ^= nums[i];
		}
		aXORb &= -aXORb;
		vector<int> ret{ 0,0 };
		for (auto item : nums) {
			ret[!(item &aXORb)] ^= item;
		}
		return ret;
	}
};
int main() {
	vector<int> v = { 1,2,2,3,1,5 };
	Solution s;
	for (auto item: s.singleNumber(v)) {
		cout << item;
	}
}