#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Solution {
	string num2str(int n) {
		stringstream ss;
		ss << n;
		return ss.str();
	}
	string transform(string &s) {
		int i = 0;
		char value = s[0];
		int count = 0;
		string result;
		for (; i < s.size(); i++) {
			if (s[i] == value){
				count++;
			}
			else {
				result += num2str(count);
				result += value;
				count = 1;
				value = s[i];
			}

		}
		result += num2str(count);
		result += value;
		return result;
	}
public:
	string countAndSay(int n) {
		string str = "1";
		string result = str;
		if (n == 0)result = "";
		for (int i = 1; i < n; i++) {
			result = transform(result);
		}
		return result;
	}
};

int main() {
	Solution s;
	int n = 3;
	string result = s.countAndSay(n);
	cout << result << endl;
}