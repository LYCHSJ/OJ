#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int ret = 0;
		int i = 0;
		while (n) {
			int acc = 1;
			for (int j = 0; j < i; j++) {
				acc *= 10;
			}
			ret = ret+n % 8*acc;
			n /= 8;
			i++;
		}
		cout << ret << endl;
	}
	return 0;
}