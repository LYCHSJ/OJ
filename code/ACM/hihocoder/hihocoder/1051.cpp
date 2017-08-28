#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int greedySolution(vector<int > v,int M) {
	if (M>=v.size()-2)return 100;
	int ret=0;
	vector<int> worktime(v.size()+1, 0);
	for (int i = 0; i < worktime.size(); i++) {
		if (i == 0)worktime[i] = v[i] - 0 - 1;
		if (i == worktime.size() - 1)worktime[i] = 100 - v[i - 1];
		if (i > 0 && i < worktime.size() - 1)worktime[i] = v[i] - v[i - 1] - 1;
	}
	for (int j = 0; j < M; j++) {

	}
	for (int i = 0; i < worktime.size() - 1; i++) {
		if (worktime[i] + worktime[i + 1]>ret)ret = worktime[i] + worktime[i + 1]+1;
	}
	return ret;
}
int main() {
	int num;
	cin >> num;
	int N, M;
	vector<int> ret(num, 0);
	for (int i = 0; i < num; i++) {
		cin >> N >> M;
		vector<int> v(N, 0);
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		ret[i]=greedySolution(v,M);
	}
	for (int i = 0; i < num; i++) {
		cout << ret[i] << endl;
	}
	return 0;
}