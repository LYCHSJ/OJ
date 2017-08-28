#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N, M;
	vector<vector<int> > v;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		v.push_back({0});
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a][0]++; 
		v[b][0]++;
	}
	int count = 0;
	for (auto item : v) {
		if ((item[0]) % 2 != 0)count++;
	}
	if (count == 2 || count == 0)cout << "Full" << endl;
	else cout << "Part" << endl;
	return 0;
}