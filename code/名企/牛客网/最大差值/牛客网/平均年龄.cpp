#include<iostream>
using namespace std;
int main() {
	double W, Y, x;
	int N;
	while (cin >> W >> Y >> x >> N) {
		while (N--) {
			Y = (Y + 1)* (1 - x) + 21 * x;
		}
		int ret = (Y - int(Y) == 0) ? Y : Y + 1;
		cout << ret << endl;
	}
}