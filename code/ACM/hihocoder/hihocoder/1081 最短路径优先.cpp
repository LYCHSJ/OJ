#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxlength = 1001;
int N, M, S, T;
int A[1000][1000];
int dist[1000];
int pre[1000];
bool v[1000];

int Dijstra() {
	for (int i = 0; i < N; i++) {
		dist[i] = A[S][i];
		v[i] = false;
		if (dist[i] == maxlength) pre[i] = 0;
		else pre[i] = S;
	}
	dist[S] = 0;
	v[S] = true;
	for (int i = 1; i < N; i++) {
		int mindist = maxlength;
		int u = S;
		for (int j = 0; j < N; j++) {
			if (!v[j] && dist[j] < mindist) {
				mindist = dist[j];
				u = j;
			}
		}
		v[u] = true;
		//¸üÐÂdist
		for (int j = 0; j < N; j++) {
			if (!v[j] && A[u][j]<maxlength) {
				if (dist[u] + A[u][j] < dist[j]) {
					mindist = dist[u] + A[u][j];
					pre[j] = u;
					dist[j] = mindist;
				}
			}
		}
	}
	return dist[T];
}
int main() {
	cin >> N >> M >> S >> T;
	for (int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			A[i][j] = maxlength;
		}
	}
	S--;
	T--;
	fill(v, v + 1000, 0);
	fill(dist, dist + 1000, maxlength);
	while (M--) {
		int i; int j;
		cin >> i >> j;
		i--;
		j--;
		int length;
		cin >> length;
		if (A[i][j]>length) {
			A[i][j] = length;
			A[j][i] = length;
		}

	}
	cout << Dijstra() << endl;
	return 0;
}