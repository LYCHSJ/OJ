#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> array) {
		if (array.size() == 0) return 0;
		int first = 0, last = array.size() - 1;
		int mid = (first + last) / 2;
		while (array[first] >= array[last]) {
			if (last - first == 1) return array[last];
			if (array[first] == array[mid] && array[mid] == array[last]) {
				// linear search
				int min = array[first];
				for (int i = first + 1; i <= last; i++)
					min = array[i]<min ? array[i] : min;
				return min;
			}
			if (array[first] <= array[mid]) first = mid;
			else last = mid;
			mid = (first + last) / 2;
		}
		return array[first];
	}
};