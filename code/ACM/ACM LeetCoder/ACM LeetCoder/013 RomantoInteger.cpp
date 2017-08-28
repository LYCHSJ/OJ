#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int result=0;
		map<char, int> nums = {
			{'I',1},
			{'V',5},
			{'X',10},
			{'L',50},
			{'C',100},
			{'D',500},
			{'M',1000}
		};
		char index;//nums下标
		int i;//循环次数
		int tmp;//单元数
		int left=0;//左部
		int right=0;//右部
		if (s.length() == 1) {
			result = nums[s[0]];
			return result;
		}//长度为1
		for (i = 0; i < s.length(); i++) {

			if (findright(s, i)) {
				right = nums[s[i + 1]];
				left = nums[s[i]];
				i++;
			}
			else {
				right = nums[s[i]];
				left = 0;
			}

			tmp = right - left;
			result += tmp;
		}//长度大于1

		return result;

	}
	bool findright(string s,int i){
		if (i == s.length() - 1)return false;
		if (s[i] == 'I' && s[i + 1] == 'V')return true;
		if (s[i] == 'I' && s[i + 1] == 'X')return true;
		if (s[i] == 'V' && s[i + 1] == 'X')return true;
		if (s[i] == 'X' && s[i + 1] == 'L')return true;
		if (s[i] == 'X' && s[i + 1] == 'C')return true;
		if (s[i] == 'L' && s[i + 1] == 'C')return true;
		if (s[i] == 'C' && s[i + 1] == 'D')return true;
		if (s[i] == 'C' && s[i + 1] == 'M')return true;
		if (s[i] == 'D' && s[i + 1] == 'M')return true;
		return false;
	}

};

int main() {
	string rn = "D";
	Solution s;
	cout << s.romanToInt(rn) << endl;
	return 0;
}