#include<iostream>
using namespace std;
class Solution {
public:
	/**
	* ����������ζ����Ʊ��λ����ͬ������
	*
	* @param m ����m
	* @param n ����n
	* @return ����
	*/
	int countBitDiff(int m, int n) {
		int ret = m^n;
		int count = 0;
		while (ret) {
			ret &= (ret -1);
			count++;
		}
		return count;
	}
};
int main() {
	Solution s;
	int m = 1999;
	int n = 2299;
	cout << s.countBitDiff(m, n) << endl;
	return 0;
}