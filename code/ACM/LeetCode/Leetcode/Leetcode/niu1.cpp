#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
int N, L;
vector<int> ret;
void sum_c() {
	vector<int> partsum(N, 0);
	vector<int> num;
	for (int i = 0; i<N; i++) {
		num.push_back(i + 1);
	}
	partial_sum(num.begin(), num.end(), partsum.begin());
	for (int i = L; i <= N; i++) {
		for (int j = 0; j<N - L; j++) {
			if ((partsum[j + L - 1] - partsum[j] + num[j]) == N) {
				for (int k = j; k <= j + L - 1; k++) {
					ret.push_back(k);
				}//Êä³öret
			}
		}
	}
}
int main() {
	cin >> N >> L;
	sum_c();
	for (int i = 0; i<ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}