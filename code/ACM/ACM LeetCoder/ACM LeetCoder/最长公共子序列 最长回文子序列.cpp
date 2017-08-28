#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int T;
int LCS(string s1, string s2) {
	vector<int> v2(s2.size()+1, 0);
	vector<vector<int> > v(s1.size()+1, v2);
	for (int j = 0; j < s2.size(); j++) {
		v[0][j] = 0;
	}
	for (int i = 0; i <= s1.size(); i++) {
		v[i][0] = 0;
	}
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
			}
			else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}
	return v[s1.size()][s2.size()];
}
int main() {
	string s;
	while (cin>>s) {
		string s2(s);
		reverse(s2.begin(),s2.end());
		int ret=LCS(s, s2);
		cout << s.size() - ret << endl;
	}
}