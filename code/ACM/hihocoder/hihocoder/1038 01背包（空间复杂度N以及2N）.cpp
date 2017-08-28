#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int M;
int best[100001];
int getSum(vector<int> value, vector<int> need) {
	for (int i = 0; i <N; i++) {
		for (int j = M; j>=need[i]; j--) {
			best[j] = max(best[j], best[j - need[i]] + value[i]);
		}
	}
	return best[M];
}
int main() {
	vector<int> value;
	vector<int> need;
	cin >> N >> M;
	fill(best, best + 100001, 0);
	for (int i = 0; i < N; i++) {
		int weight;
		cin >> weight;
		need.push_back(weight);
		int price;
		cin >> price;
		value.push_back(price);
	}
	cout << getSum(value,need) << endl;
	return 0;
}