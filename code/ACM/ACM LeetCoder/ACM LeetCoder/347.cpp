#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> v;
		unique_copy(nums.begin(), nums.end(), v.begin());
		map<int, int> m;
		for (auto item : v) {
			m.insert(make_pair(item, 0));
		}
		for (auto item : nums) {
			m[item]+=1;
		}
		while (k) {
			for (int i = 0; i < v.size() - k; i++) {
				if (v[i] >= v[i + 1]) {
					int tmp = v[i];
					v[i] = v[i + 1];
					v[i + 1] = tmp;
				}
			}
			k--;
		}
		vector<int>ret;
		copy(v.end() - k, v.end() - 1, ret.begin());
		return ret;
	}
};
int main() {
	vector<int> v = { 1,2,1,2,1,3 };
	Solution s;
	vector<int> num = s.topKFrequent(v, 2);
	for (auto item : num) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}