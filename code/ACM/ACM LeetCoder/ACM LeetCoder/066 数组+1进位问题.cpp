#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int add = 0;
		digits[digits.size() - 1] ++;
		for (int i = digits.size() - 1; i >= 0; i--) {
			digits[i] = digits[i] + add;
			if (digits[i]>9) {
				digits[i]  = digits[i] %10;
				add = 1;
			}
			else {
				add = 0;
			}
		}
		if (add == 1)digits.insert(digits.begin(),1);
		return digits;
	}

};

int main() {
	Solution s;
	vector<int> nums = { 9,9,9,9,9,9,9 };
	vector<int > result = s.plusOne(nums);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	cout << endl;
	return 0;
}