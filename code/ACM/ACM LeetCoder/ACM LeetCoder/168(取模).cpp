#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string result;

		while (n-- !=0) {
			int tail = n % 26;
			result =  char(tail + 'A')+ result;
			n /= 26;
		}
		return result;
	}
};
int main() {
	Solution s;
	int x = 26;
	cout << s.convertToTitle(x) << endl;
}