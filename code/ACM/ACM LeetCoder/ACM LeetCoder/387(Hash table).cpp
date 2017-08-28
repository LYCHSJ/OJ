#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int > v(26,0);
		int index=-1;
		for (auto item : s) {
			v[int(item) - 97]++;
		}
		int tmp;
		for (int i = 0; i < v.size();i++) {
			if (v[i] == 1) {
				tmp= s.find(char(i + 97));
				if (index == -1) {
					index = tmp;
				}
				if (index != -1 && index > tmp) {
					index = tmp;
				}			
			}
		}
		return index;
	}
};
int main() {
	string str = "lleett";
	Solution s;
	cout << s.firstUniqChar(str) << endl;
	return 0;
}