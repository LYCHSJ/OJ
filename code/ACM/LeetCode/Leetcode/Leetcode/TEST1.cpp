#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
using namespace std;
vector<int> vec;
int a, b, c;
struct index {
	int m2;
	int m3;
};
bool judge() {
	vector<map<int, int> > sum_beforem1(vec.size(), {});
	vector<map<int, int> > sum_afterm3(vec.size(), {});
	int i = 1, int j = vec.size() - 2;
	int sum = 0;
	while (i < vec.size() - 6) {
		sum += vec[i-1];
		if (sum_beforem1[sum]!=i) {   // sum在sum_beforem1中

		}
		else {// sum不在sum_beforem1中
			sum_beforem1.push_back({ sum,i });
		}

		i++;
	}
	int sum = 0;
	while (j >= 6) {
		sum += vec[j+1];
		sum_afterm3.push_back({sum,i});
		j--;
	}
}
int main() {
	vector<int> a = { 2,5,1,1,1,1,4,1,7,3,7 };
	vec = a;
	cout << judge() << endl;
	return 0;
}