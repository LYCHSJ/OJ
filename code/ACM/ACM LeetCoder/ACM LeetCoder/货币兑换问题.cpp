/*��N��Ǯ������1Ԫ��5Ԫ��10Ԫ����ϣ����ж�����������*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int getWays(int n) {
		int ret;
		vector<int> ways(n+1,0);
		for (int i = 1; i < 5; i++) {
			ways[i] = 1;
		}
		for (int i = 5; i < 10; i++) {
			ways[i] = 2;
		}
		ways[10] = 3;
		if (n > 10) {
			for (int i = 11; i < n + 1; i++) {
				
			}
		}
		else return ret= ways[n];
		return ret = ways[n - 1];
	}
};
int main() {
	int n = 14;
	Solution s;
	cout << s.getWays(n) << endl;
}