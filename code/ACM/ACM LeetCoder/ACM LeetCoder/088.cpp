#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> tmp1;
		for (int i = 0; i < m; i++) {
			tmp1.push_back(nums1[i]);
		}
		vector<int> tmp2;
		for (int i = 0; i < n; i++) {
			tmp2.push_back(nums2[i]);
		}
		if (m == 0) { 
			nums1 = tmp2; 
			return; }
		if (n == 0)return;
		vector<int > result;
		vector<int>::iterator it_nums1 = tmp1.begin();
		vector<int>::iterator it_nums2 = tmp2.begin();
		while (it_nums1 != tmp1.end() && it_nums2 != tmp2.end()) {
			if (*it_nums1 > *it_nums2) {
				result.push_back(*it_nums2);
				it_nums2++;
			}
			else {
				result.push_back(*it_nums1);
				it_nums1++;
			}
		}
		if (it_nums1 != tmp1.end()) {
			while (it_nums1 != tmp1.end()) {
				result.push_back(*it_nums1);
				it_nums1++;
			}
		}
		else {
			while (it_nums2 != tmp2.end()) {
				result.push_back(*it_nums2);
				it_nums2++;
			}
		}
		nums1.clear();
		nums1 = result;
	}
};

int main() {
	Solution s;
	vector<int > nums1 = {2};
	vector<int > nums2 = {1};
	s.merge(nums1, nums1.size(), nums2, nums2.size());
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	return 0;
}