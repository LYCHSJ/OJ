#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector<int> a;
 vector<int>b;
 int judge(int q, int p) {
	 sort(a.begin(), a.end());
	 sort(b.begin(), b.end());
	 if (q > a[a.size() - 1])return 0;
	 if (p > b[b.size() - 1])return 0;
 }
int main() {
	int n, m;
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		int a1;
		cin >> a1;
		a.push_back(a1);
	}
	for (int i = 0; i < n; i++) {
		int b1;
		cin >> b1;
		b.push_back(b1);
	}
	while (m--) {
		int q, p;
		cin >> q >> p;
		cout << judge(q, p) << endl;
	}
}