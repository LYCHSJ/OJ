#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		if (n == 1) {
			v.push_back("()");
			return v;
		}
		int indexnumber = 2 * n;
		string str;
		str += "(";
		indexnumber--;
		while (indexnumber) {
			str+=" ";
			indexnumber--;
		}
		str += ")";
		if (n > 1) {
			string str = "()";
			int count = n - 1;
			parenthesis(v, n);
		}
	}
	vector<string> parenthesis(vector<string> v,int n) {
		if (n) {

		}
	}
};
int main() {
	return 0;
}