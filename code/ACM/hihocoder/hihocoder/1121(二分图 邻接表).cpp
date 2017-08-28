#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<string>
using namespace std;
int T;
int N, M;
int A, B;
const int maxN = 10000;
const int maxM = 40000;
array<vector<int>, maxN + 1> Graph;

bool isBinaryGraph(vector<int> color) {
	color[0] = 0;
	while (find(color.begin(), color.end(), -1) != color.end()) {
		for (int u = 0; u < N; u++) {
			if (color[u] == -1)continue;
			for (int j = 0; j < Graph[u].size(); j++) {
				int v = Graph[u][j];
				if (color[v] == -1)color[v] = color[u] ^ 1;
				else if (color[u] == color[v])return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<int> vec;
		vector<int> color(N, -1);
		fill(Graph.begin(), Graph.end(), vec);
		for (int i = 0; i < M; i++) {
			cin >> A>> B;
			A--;
			B--;
			Graph[A].push_back(B);
		}//ÁÚ½Ó±íÌî³ä
		string ret = isBinaryGraph(color) ? "Correct" : "Wrong";
		cout << ret << endl;
	}
	return 0;
}