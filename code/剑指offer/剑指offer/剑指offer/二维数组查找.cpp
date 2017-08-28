#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int n = array.size();
		int m = array[0].size();
		int i = 0; int j = m - 1;
		while (i < n&&j >= 0) {
			if (array[i][j] == target)return true;
			if (array[i][j]<target)++i;
			else --j;
		}
		return false;
	}
};
int main() {
	vector<vector<int> > array = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Solution s;
	cout << s.Find(7, array) << endl;
}