#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> left(nums.size(),1);
		for (int i = 0; i < nums.size()-1; i++) {
			left[i + 1] *= nums[i] * left[i];
		}
		vector<int > right(nums.size(), 1);
		int p = 1;
		for (int i = nums.size() - 1; i > -1; i--) {
			left[i]*=p;
			p *= nums[i];
		}
		return left;
	}
};
int main() {
	Solution s;
	vector<int > num = { 1,2,3,4 };
	vector<int>product = s.productExceptSelf(num);
	for (auto item : product) {
		cout << item;
	}
	cout << endl;
}