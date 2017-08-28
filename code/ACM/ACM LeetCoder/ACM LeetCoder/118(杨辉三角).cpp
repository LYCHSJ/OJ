#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v(numRows);
		for (int i = 0; i < numRows; i++) {
			v[i].resize(i + 1);
			v[i][0] = v[i][i] = 1;
			for (int j = 1; j < i; j++) {
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
			}
		}
		return v;
	}
};
int main() {
	int numRows;
	cin >> numRows;
	Solution s;
	vector<vector<int>> v=s.generate(numRows);
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