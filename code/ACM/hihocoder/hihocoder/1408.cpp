#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	vector<int > nums(4, 0);
	vector<int> space(4, 0);
	for (int come = 0; come < 4; come++) {
		cin >> nums[come];
	}
	int hour=0;
	int min = 0;
	int ret = 24;
	vector<int>A;
	vector<int>B;
	vector<int>C;
	vector<int>D;
	int a, b, c, d;
	for (int i = 0; i < 4; i++) {
		if (nums[i] < 3)A.push_back(nums[i]);
		if (nums[i < 6])C.push_back(nums[i]);
		D.push_back(nums[i]);
	}
	if (A.size() == 1 && A[0] == 2) {
		for (int i = 0; i < 4; i++) {
			if (nums[i] < 4)B.push_back(nums[i]);
		}
	}
	else for (int i = 0; i < 4; i++) {
		B.push_back(nums[i]);
	}
	a = *max_element(A.begin(), A.end());

	cout << hour << ":" << min << endl;
}