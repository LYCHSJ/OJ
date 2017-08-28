#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int> x(n,0);
		vector<int> y(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		int xmin = x[0], xmax = x[0], ymin = y[0], ymax = y[0];
		for (int i = 1; i < n; i++) {
			if (xmin > x[i])xmin = x[i];
			if (xmax < x[i])xmax = x[i];
			if (ymin > y[i])ymin = y[i];
			if (ymax < y[i])ymax = y[i];
		}
		int v = (ymax - ymin)>(xmax - xmin) ? ((ymax - ymin)*(ymax - ymin)) : ((xmax - xmin)*(xmax - xmin));
		cout << v << endl;
	}
	return 0;
}