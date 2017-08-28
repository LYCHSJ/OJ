#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string reverseVowels(string s) {
		if (s.empty())return s;
		int left = 0;
		int right = s.size() - 1;
		while(left<right){
			if (!isVowel(s[left])) {
				left++; 
			}
			else if (!isVowel(s[right])) {
				right--; 
			}
			else {
					char tmp = s[left];
					s[left] = s[right];
					s[right] = tmp;
					left++;
					right--;
			}			
		}
		return s;
	}
	bool isVowel(char word) {
		return word == 65 || word == 69|| word == 73 || word ==79 || word ==85 || word == 97 || word == 101 || word == 105 || word == 111 || word == 117 ? true : false;
	}
};
int main() {
	Solution s;
	string str = "Aa";
	cout << s.reverseVowels(str) << endl;
	return 0;
}