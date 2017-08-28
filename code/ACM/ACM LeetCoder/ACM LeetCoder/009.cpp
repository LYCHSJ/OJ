#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		bool result = false;
		if (x<0)return result;
		if (x == 0)return true;
		int tmp;
		vector<int> nums;
		while (x>0)
		{
			tmp = x % 10;
			nums.push_back(tmp);
			x /= 10;

		}
		int p = 0;
		int q = nums.size() - 1;
		while (p<q)
		{
			if (nums[p] != nums[q]) return result;
			p++;
			q--;
		}
		result = true;
		return result;
	}
};

int main() {
	int x= 0;
	Solution s;
	cout << s.isPalindrome(x) << endl;
	return 0;
}