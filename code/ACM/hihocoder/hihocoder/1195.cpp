#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Eq_Zr(double x)
{
	return x < 1e-6 && x > -1e-6;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<double> f(N, 0);
	vector<vector<double> >fg(M, f);
	vector<double> y(M, 0);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> fg[i][j];
		}
		cin >> y[i];
	}
	//上三角矩阵
	bool manySolutionFlag = false;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		flag = false;
		for (int j = i; j < M; j++) {
			if (!Eq_Zr(fg[i][j])) {
				swap(fg[i], fg[j]);
				flag = true;
				break;
			}
		}
		if (!flag) {
			manySolutionFlag = true;
			cout <<"Many solutions" << endl;
			return 0;
		}
		for (int j = i + 1; j < M; j++) {
			double KK = fg[j][i] / fg[i][i];
			for (int k = 0; k < N; k++) {
				fg[j][k] = fg[j][k] - fg[i][k] * KK;
			}
			y[j] = y[j] - y[i] * KK;
		}
	}
	//0=x 无解；
	for (int i = 0; i < M; i++) {
		int tmp = 0;
		for (int j = 0; j < N; j++) {
			if (fg[i][j] != 0)tmp = 1;
		}
		if (tmp == 0 && y[i] != 0) {
			cout << "No solutions" << endl;
			return 0;
		}
	}
	//唯一解
	vector<int> val(N, 0);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			y[i] = y[i] - fg[i][j] * val[j];
			fg[i][j] = 0;
		}
		val[i] = y[i] / fg[i][i];
	}
	for (int i = 0; i < N; i++) {
		cout << val[i] << endl;
	}
	return 0;
}