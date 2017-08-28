#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, t, c;
	while (cin >> n >> t >> c) {
		vector<int> a(n,0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int method = 0;
		int sum = 0;
		for (int i = 0; i < c; i++) {
			sum += a[i];
		}
		if (sum >= c)method = 1;
		for (int i = c; i < n; i++) {
			sum = sum - a[i - c] + a[i];
			method= sum > t ? method: method+ 1;
		}
		cout << method<< endl;
	}
	return 0;
}