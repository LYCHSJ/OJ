#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
vector<int> vec;
int a, b, c;
struct index {
	int m2;
	int m3;
};
bool judge() {
	int n = vec.size();
	vector<int> sum(n,0);
	sum[n - 1] = vec[n - 1];
	int total_sum = accumulate(vec.begin(), vec.end(), 0);//O(n)
	for (int i = n - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + vec[i];
	}//O(n),
	vector<index> M3;
	for (int m2 = 3; m2 < n - 3; m2++) {
		for (int m3 = m2 + 2; m3 < n - 1; m3++) {
			if (sum[m2 + 1] - vec[m3] == 2*sum[m3 + 1]) {
				M3.push_back({m2,m3});
			}
		}
	}//O(n^2)
	int m3_size = M3.size();
	for (int j = 0; j < M3.size(); j++) {
		for (int m1 = M3[j].m2 - 2; m1 >= 0; m1--) {
			if ((sum[m1 + 1] - sum[M3[j].m2]) == sum[M3[j].m3 + 1]) {
				if ((total_sum - sum[m1]) == sum[M3[j].m3 + 1]) {
					a = m1;
					b = M3[j].m2;
					c = M3[j].m3;
					cout << a << " " << b << " " << c << endl;
					return true;
				}
			}
		}
	}//O(M3.size()*n);
	return false;
}

int main() {
	vector<int> a = { 2,5,1,1,1,1,4,1,7,3,7 };
	vec = a;
	cout<<judge()<<endl;
	return 0;
}