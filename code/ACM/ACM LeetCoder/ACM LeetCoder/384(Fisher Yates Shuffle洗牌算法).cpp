#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	vector<int> vi, vo;
public:
	Solution(vector<int> nums) {
		vi = vo = nums;
	}

	vector<int> reset() {
		return vi = vo;
	}

	vector<int> shuffle() {
		int i = 0, j = 0;
		for (i = vi.size() - 1; i > 0; --i) {
			j = rand() % (i + 1);
			int tmp = vi[i];
			vi[i] = vi[j];
			vi[j] = tmp;
		}
		return vi;
	}
};