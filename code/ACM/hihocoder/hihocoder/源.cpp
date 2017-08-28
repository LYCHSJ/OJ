#include<iostream>
#include<vector>
using namespace std;
class solution {
public:
	void printSubarray(vector<int> & nums) {
		int length = nums.size();
		int n = pow(2, length);
		vector<int> *totalsub;
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i];
		}
		cout << endl;
		subarray(nums);
	}
	void subarray(vector<int> nums) {
		if (nums.size() > 1) {
			vector<int> tmp (nums);
			for (auto it = tmp.begin(); it!= tmp.end(); it++) {
				if (it == tmp.end() - 1)tmp.pop_back();
				else it = tmp.erase(it);
				for (int i = 0; i < tmp.size(); i++) {
					cout << tmp[i];
				}
				cout << endl;
				subarray(tmp);
				tmp = nums;
			}
		}
	}
};
int main() {
	solution s;
	vector<int> nums = { 0,1,2,3 };
	s.printSubarray(nums);
	return 0;
}