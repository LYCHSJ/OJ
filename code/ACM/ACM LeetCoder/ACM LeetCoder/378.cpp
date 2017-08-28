#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int row, col = matrix.size();
		int half = (1 + row)*row / 2;
		int preNum = 0;
		int target = 0;
		if (k > half) {
			k = row*row-k;
		}
		else {
			for (int i = 0; i < row; i++) {
				int Num = (1 + i + 1)*i + 1 / 2;
				if (k > preNum&&k <= Num) {
					target = i;
					break;
				}
				preNum = Num;
			}
		}
		vector<int> subNum;
		int target_num = 0;
		
		if (k > half) {
			target = row;
			for (int i = row-i; i < target + 1; i++) {
				subNum.push_back(matrix[][row]);
				
			}
		}
		else {
			for (int i = 0; i < target + 1; i++) {
				subNum.push_back(matrix[i][i]);
			}
		}

		
		for (int point = 0; point < k; point++) {
			for (int j = subNum.size()-1; j >point; j--) {
				if (subNum[j - 1] >= subNum[j]) {
					int tmp = subNum[j - 1];
					subNum[j - 1] = subNum[j];
					subNum[j] = tmp;
				}
			}
			point++;
		}
		return subNum[k - preNum];
	}
};
int main() {
	vector<vector<int> > v = { {1,5,9},{10,11,13},{12,13,15} };
	Solution s;
	int k = 8;
	cout << s.kthSmallest(v,k) << endl;
	return 0;
}