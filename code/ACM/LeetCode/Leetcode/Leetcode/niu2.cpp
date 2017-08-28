#include<iostream>
#include<vector>
using namespace std;
long long n;
long long p, q;
bool Method() {
	long long b = 2;
	int cnt = 0;
	int yincnt = 0;
	long long min;
	vector<long long> yin(n, 0);
	while (b <= n / 2) {
		if (n%b != 0)b++;
		else {
			if (yin[b] == 1) { b++; continue; }
			else if (yincnt == 0) {
				min = b;
				for (int i = 1; i*b<n; i = i*b) {
					yin[i*b] = 1;
				}
				yincnt++;
			}
			else return false;//有其他因数
			b++;
		}
	}//O(n)
	int c = n;
	while (c != 1) {
		cnt++;
		c /= min;
	}
	p = min; q = cnt;
	return true;
}
int main() {
	cin >> n;
	if (Method()) {
		cout << p << " " << q << endl;
	}
	else cout << "No" << endl;
	return 0;
}