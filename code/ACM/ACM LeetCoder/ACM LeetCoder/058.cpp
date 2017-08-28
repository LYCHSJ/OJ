#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		stringstream line(s);
		string word;
		int count = 0;
		while(line>>word){
			count = word.size();
		}
		return count;
	}
};
int main() {
	Solution s;
	string str = " ";
	cout << s.lengthOfLastWord(str) << endl;
	return 0;
}