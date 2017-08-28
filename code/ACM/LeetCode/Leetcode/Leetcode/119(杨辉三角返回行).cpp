#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> v1 = {1,1};
		vector<int> v2 = {1};
		if (1 == rowIndex)return v1;
		if (0 == rowIndex)return v2;
		for (int i = 1; i <= rowIndex; i++) {
			if (i % 2 == 1) {
				v1.resize(i+1);
				v1[0] = v1[i] = 1;
				for (int j = 1; j < i; j++) {
					v1[j] = v2[j - 1] + v2[j];
				}
			}
			else {
				v2.resize(i + 1);
				v2[0] = v2[i] = 1;
				for (int j = 1; j < i; j++) {
					v2[j] = v1[j - 1] + v1[j];
				}
			}
		}
		if ((rowIndex) % 2 == 1)return v1;
		else return v2;
	}
};
int main() {
	int numRows;
	cin >> numRows;
	Solution s;
	vector<vector<int>> v = s.getRow(numRows);
	if (numRows != NULL) {
		cout << "[" << endl;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
		cout << "]" << endl;
	}
}