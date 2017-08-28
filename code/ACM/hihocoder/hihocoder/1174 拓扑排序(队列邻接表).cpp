#include<iostream>
#include<vector>
#include<queue>
#include<array>
#include<string>
using namespace std;
int T;
int N, M;
int A, B;
const int maxN = 100000, maxM = 500000;
array<vector<int>, maxN + 1> Graph;
queue<int> que;
int degree[maxN + 1];
bool topolgySorting() {
	bool ret;
	int cnt = 0;
	for (int u = 1; u < N + 1; u++) {
		if (degree[u] == 0)	que.push(u);
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		cnt++;
		for (int idx = 0; idx < Graph[u].size(); idx++) {
			int v = Graph[u][idx];
			degree[v]--;
			if (!degree[v])que.push(v);
		}
	}
	return ret = !(N > cnt);
}
int main() {
	cin >> T;
	while(T--){
		vector<int> vec;
		fill(Graph.begin(), Graph.end(), vec);
		fill(degree, degree + maxN + 1, 0);
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> A >> B;
			Graph[A].push_back(B);
			degree[B]++;
		}
		bool ret = topolgySorting();
		string result = ret ? "Correct" : "Wrong";
		cout << result << endl;
	}
}