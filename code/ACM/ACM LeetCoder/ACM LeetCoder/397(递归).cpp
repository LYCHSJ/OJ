#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int integerReplacement(int n) {
		int count = 0;

		while (n != 1) {
			count++;
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				int a = integerReplacement(n + 1);				
				int b = integerReplacement(n - 1);
				if (a >= b) {
					count += b;
				}
				else {
					count += a;
				}
				n = 1;
			}
		}
		return count;	
	}
};

int main() {
	Solution s;
	int x = 2147483647;
	cout << s.integerReplacement(x) << endl;
	return 0;
}