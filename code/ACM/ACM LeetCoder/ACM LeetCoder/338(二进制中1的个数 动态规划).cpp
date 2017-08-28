#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v;
		for (int i = 0; i <= num; i++) {
			int count = 0;
			int number = i;
			while (number) {
				number &= (number - 1);
				count++;
			}
			v.push_back(count);
		}
		return v;
	}
};
int main() {
	Solution s;
	int num = 4;
	vector<int> abc = s.countBits(num);
	for (int i = 0; i < abc.size(); i++) {
		cout << abc[i]<<" ";
	}
	cout << endl;
	return  0;
}