#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> v(256, 0);
		int length = 0;
		for (auto c : s) {
			if (++v[c - '\0'] %2== 0) {
				length += 2;
			}
		}
		if (length != s.size())length++;
		return length;
	}
};
int main() {

}