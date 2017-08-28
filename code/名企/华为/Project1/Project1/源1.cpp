#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool judge(vector<int> num) {
	bool flag = true;
	for (int i = 0; i < 10; i++) {
		if (num[i] != 0)flag = false;
	}
	if (flag)return true;
	for (int i = 0; i < 10; i++) {
		if (num[i] != 0) {
			if (i+2<10) {
				if (num[i + 1] != 0 && num[i + 2] != 0) {
					num[i]--;
					num[i + 1]--;
					num[i + 2]--;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] == 0)return flag = true;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] == 3||num[i]==0)return flag = true;
	}
	return true;
}
bool hu(string in) {
	vector<int>v = { 2,5,8,11,14 };
	int l = in.size();
	if (l < 2 || l>14 || l % 3 != 2)return false;
	vector<int> num(10, 0);
	for (int i = 0; i < l; i++) {
		num[in[i] - '0']++;
	}//¸öÊý
	bool is_exist2 = false;
	for(int i = 0; i < 10; i++) {
		if (num[i] >= 2) {
			is_exist2 = true;
			break;
		}
	}
	if (!is_exist2)return false;
	if (l == 2&& (num[in[0] - '0'] == 2)) {
		return true;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] == 2 || num[i] == 4) {
			num[i] -= 2;
			bool thisturn= judge(num);
			if (thisturn == true)return true;
		}
	}
	return false;
}
int main() {
	string in;
	cin >> in;
	if (hu(in))cout << "yes" << endl;
	else cout << "no" << endl;
}