#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int > result;
		vector<int> v;
		//if (nums1.size > nums2.size())swap(nums1, nums2);
		if (nums1.empty() || nums2.empty())return result;
		int first1 = 0;
		int first2 = 0;
		int len1 = nums1.size();
		int len2 = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (first1 != len1&& first2 != len2) {
			if (nums1[first1] < nums2[first2])first1++;
			else if (nums2[first2]<nums1[first1])first2++;
			else {
				if(!v.size()||v.back()!=nums1[first1])result.push_back(nums1[first1]);
				first1++;
				first2++;
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums1 = { 1,2,3,5,8,9 };
	vector<int> nums2 = { 3,5,7 };
	Solution s;
	vector<int > v;
	v = s.intersection(nums1, nums2);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}






