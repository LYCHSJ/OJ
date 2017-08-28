#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int best[10001];
int p[10001];
int q[10001];
int getSum(vector<int> need, vector<int> value) {
	int k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j % 2 == 1) {
				if (j < need[i]) {
					p[j] = q[j];
				}
				else {
					p[j] = max(q[j], q[j - need[i] * k] + value[i] * k);
				}
			}

		}
	}
}
int main() {
	cin >> N >> M;
	vector<int> value(N, 0);
	vector<int> need(N, 0);
	fill(best, best+10001, 0);
	for (int i = 0; i < N; i++) {
		cin >> need[i];
		cin >> value[i];
	}
	cout << getSum(need, value) << endl;
}