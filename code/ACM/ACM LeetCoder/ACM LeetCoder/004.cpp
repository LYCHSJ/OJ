#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double result;
		if (nums1.empty() && nums2.empty()) return result = NULL;
		if (nums1.empty())return result = (double)nums2[(nums2.size() -1)/ 2];
		if (nums2.empty())return result = (double)nums1[(nums1.size() - 1) / 2];

		if (nums1.size() == 1 && nums2.size() == 1) return result = (nums1[0] + nums2[0]) / 2;

		//对两个数组取中位数，递归执行
		int left1 = 0;
		int left2 = 0;
		int right1 = nums1.size() - 1;
		int right2 = nums2.size() - 1;
		int tmp1;
		int tmp2;
		while (true) {
			tmp1 = findMedianIndex(nums1, left1, right1);
			tmp2 = findMedianIndex(nums2, left2, right2);
			if (right1 - left1 > 1 || right2 - left2 > 1) {
				if (nums1[tmp1] == nums2[tmp2]) {
					result = nums1[tmp1];
					break;
				}
			}

			if (nums1[tmp1] < nums2[tmp2]) {
				if ((right1 - left1) % 2 == 0)left1 = tmp1;//奇数情况
				if ((right1 - left1) % 2 == 1)left1 = tmp1 + 1;//偶数情况
				right2 = tmp2;
			}
			if (nums1[tmp1] > nums2[tmp2]) {
				if ((right2 - left2) % 2 == 0)left2 = tmp2;
				if ((right2 - left2) % 2 == 1)left2 = tmp2 + 1;
				right1 = tmp1;
			}

			if (right1-left1==1 && right2-left2==1) {
				break;
			}

		}
		vector<int> arraynums = { nums1[left1],nums1[right1],nums2[left2],nums2[right2] };
		sort(arraynums.begin(), arraynums.end());
		result = (double(arraynums[1] + arraynums[2])) / 2;//全偶
		return result;


	}
	int findMedianIndex(vector<int>& nums, int left, int right) {
		int tmp;
		tmp = (left + right) / 2;
		return tmp;
	}

};

int main() {
	vector<int> nums1 = { 1,2};
	vector<int> nums2 = { 1,2,3 };
	Solution s;
	double output = s.findMedianSortedArrays(nums1, nums2);
	cout << output << endl;
	return 0;
}