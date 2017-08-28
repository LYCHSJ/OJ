#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int bulbSwitch(int n) {
		if (n == 0)return 0;
		double count = sqrt(n);
		return int(count);
	}
};
int main() {
	Solution s;
	int n = 10;
	cout << s.bulbSwitch(n) << endl;
	return 0;
}