#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
using namespace std;
void judge(vector<int> c) {
	vector<int>sum(c.size(), 0);
	vector<int> low(c.size(),0);
	vector<int>high(c.size(), 0);
	vector<int>index(c.size(), 0);
	vector<int>right(c.size(), 0);
	int l, r;
	int retr;
	for (int i = 0; i < c.size(); i++) {
		l = i; r = 0;
		for (int j = i + 1; j < c.size(); j++) {
			if (c[i + 1] < c[i])break;
			if (c[j] > c[j - 1]) {
				continue;
			}
			else if (c[j] < c[j - 1]) {
				index[i] = j-1;
				break;
			}
			else {
				break;
			}
		}
		if (index[i] != 0) {
			int j;
			for (j = index[i]; j < c.size()-1; j++) {
				if (c[j + 1] < c[j])continue;
				else {
					r = j;
					break;
				}
			}
			if (j == c.size() - 1)r = j;
		}

		if (r != 0) {
			sum[i] = r - l + 1;
			right[i] = r;
		}
		else sum[i] == 0;

	}
	int maxsum = 0;
	for (int i = 0; i < sum.size(); i++) {
		if (sum[i] > maxsum) {
			maxsum = sum[i];
			retr = right[i];
		}
	}
	if (maxsum == 0)cout << "-1" << " " << "-1" << endl;
	else cout << retr - maxsum + 1 << " " << retr;
}
int main() {
	int n;
	cin >> n;
	vector<int> c;
	while (n--) {
		int num;
		cin >> num;
		c.push_back(num);
	}
	judge(c);
}