#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Node {
	int value;
	int no;
};
bool comp(Node a, Node b) {
	return a.value < b.value;
}
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())return false;
		if (nums.size() == 1 && nums[0] == 0)return false;
		vector<Node> tmp;
		for (int i = 0; i < nums.size(); i++) {
			Node *p = new Node();
			p->value = nums[i];
			p->no = i;
			tmp.push_back(*p);
		}
		stable_sort(tmp.begin(), tmp.end(), comp);
		for (int i = 1; i < tmp.size(); i++) {
			if (!(tmp[i].value ^ tmp[i - 1].value)) {
				if (tmp[i].no - tmp[i - 1].no <= k)return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int > nums = { 1,2,3,4,5,5 };
	Solution s;
	cout << s.containsNearbyDuplicate(nums,2) << endl;
	return 0;
}