#include<iostream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
	int n, m, x, y, t;
	while (cin >> n >> m >> x >> y >> t) {
		int num = n*m;
		vector<float> p(num, 0);
		float pa = 0;
		float pb = 1;
		for (int i = 0; i < num; i++) {
			cin >> p[i];
			pa += p[i];
		}
		pa = pa / num;
		int index = (x - 1)*m + (y - 1);
		pb = 1 - pow(1-p[index],t);
		pa = 1 - pow(1-pa, t);
		cout << fixed;
		if (pa - pb<0.0000001 && pb-pa<0.0000001) {
			cout << "equal" << endl;
			cout << setprecision(2)<<pa << endl;
		}
		else if (pa > pb) {
			cout << "ss" << endl;
			cout << setprecision(2)<<pa << endl;
		}
		else {
			cout << "cc" << endl;
			cout << setprecision(2) << pb << endl;
		}
	}
	return 0;
}