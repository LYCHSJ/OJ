#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int A[100][100];
void Floyd() {
	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (i != k&&j != k&&i != j) {
					if (A[i][k] + A[k][j] < A[i][j]) {
						A[i][j] = A[i][k] + A[k][j];
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < 100; i++) {
		for (int j=0; j < 100; j++) {
			A[i][j] = 10000;
			if (i == j)A[i][j] = A[j][i] = 0;
		}
	}
	while (M--) {
		int v; int u; int length;
		cin >> v >> u>>length;
		v--; u--;
		if (A[v][u]>length) {
			A[v][u] = A[u][v] = length;
		}
	}
	Floyd();
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (flag) {
				cout << A[i][j];
				flag = false;
			}
			else {
				cout << " " << A[i][j];
			}
		}
		cout << endl;
	}
}