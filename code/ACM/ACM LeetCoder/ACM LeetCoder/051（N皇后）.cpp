#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> space(n, 0);
		vector<int> line(n, 0);

		vector<string> pre_group;
		int retline = n;
		kind(pre_group, retline, space, n);
		return ret_group;
	}
	vector<string> kind(vector<string> pre_group, int retline,vector<int> space,int n) {
		vector<string>ret;
		for (int i = 0; i < retline; i++) {
			for (int j = 0; j < space.size(); j++) {
				if (space[j] == 0) {
					string lin(n, '.');
					lin[j] = 'Q';
					space[j] = 1;
					pre_group.push_back(lin);
					retline--;

					kind(pre_group, retline, space, n);

				}
			}
		}
		if (retline == 0)ret_group.push_back(pre_group);
		return pre_group;

	}
private:
	vector<vector<string> >ret_group;
};
int main() {
	int x = 2;
	Solution s;
	s.solveNQueens(x);

}