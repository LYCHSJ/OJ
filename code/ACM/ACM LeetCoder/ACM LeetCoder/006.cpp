#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		int n = numRows;
		string result;
		if (s == "")return result;
		if (numRows == 1)return s;
		string rows;
		for (int i = 0; i < n; i++) {
			if ((i == 0) ||( i == (n - 1))) {
				for (int j = 0; i + j*(n + n - 2) < s.size(); j++) {
					rows += s[i + j*(n + n - 2)];
				}
			}
			else {
				for (int j = 0; j*(n + n - 2)< s.size(); j++) {
					if(i + j*(n + n - 2) < s.size())rows += s[i + j*(n + n - 2)];
					if(2 * (n - 1) - i + j*(n + n - 2) < s.size())rows += s[2*(n -1)- i  + j*(n + n - 2)];
				}
			}
			result += rows;
			rows.clear();
		}
		return result;
	}
};
int main() {
	Solution s;
	string str = "ABCDE";
	cout<<s.convert(str, 4)<<endl;
	return 0;
}