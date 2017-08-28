#include<iostream>
using namespace std;
class Solution {
public:
	int getSum(int a, int b) {
		int result;
		result = a^b;
		int c = (a&b) << 1;
		while(result&c)
		{
			int tmp = result;
			result = result^c;
			c = (tmp&c)<<1;
		}
		return result^c;
	}
};
int main() {
	Solution s;
	int a = -2;
	int b = -5;
	cout << s.getSum(a, b) << endl;
}