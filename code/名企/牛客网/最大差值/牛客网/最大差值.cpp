#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class LongestDistance {
public:
	int getDis(vector<int> A, int n) {
		int ret=A[1]-A[0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (A[i] - A[j]>ret)ret = A[i] - A[j];
			}
		}
		return ret;
	}
};