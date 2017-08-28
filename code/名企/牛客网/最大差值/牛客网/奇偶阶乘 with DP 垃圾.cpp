#include<iostream>
#include<vector>
using namespace std;
int main() {
	int y1, y2,n;
	while (cin >>n) {
		int jilen=0;
		int oulen = 0;
		if (n % 2 == 0) {
			oulen = jilen = n / 2;
		}
		else {
			jilen = (n + 1) / 2;
			oulen = jilen - 1;
		}
		vector<int> jiacc(jilen, 1);
		vector<int> jisum(jilen, 0);
		vector<int> ouacc(oulen, 1);
		vector<int> ousum(oulen, 1);
		jisum[0]=jiacc[0] = 1;
		ousum[0]=ouacc[0] = 2;
		int jistart = jiacc[0];
		int oustart = ouacc[0];
		for (int i = 1; i < jiacc.size(); i++) {
			jiacc[i] = jiacc[i - 1] * (jistart + 1)*(jistart + 2);
			jisum[i] = jisum[i - 1] + jiacc[i];
			jistart += 2;
		}
		for (int i = 1; i < ouacc.size(); i++) {
			ouacc[i] = ouacc[i - 1] * (oustart + 1)*(oustart + 2);
			ousum[i] = ousum[i - 1] + ouacc[i];
			oustart += 2;
		}
		cout << jisum[jilen - 1] << " " << ousum[oulen - 1] << endl;
	}
}