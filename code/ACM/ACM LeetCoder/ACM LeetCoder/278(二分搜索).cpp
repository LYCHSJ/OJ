#include<iostream>
using namespace std;
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 0, end = n;
		n = start / 2 + end / 2;
		while (start != end) {
			if (isBadVersion(n))
				end = n;
			else
				start = n + 1;
			n = start / 2 + end / 2;
		}
		return start;
	}
};