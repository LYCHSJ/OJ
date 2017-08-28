#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <iomanip>
using namespace std;
#define PI 3.1415926
int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v[i]=num;
	}
	vector<int>map(10, 0);
	int i = 0;
	int index = 0;
	int pre = 0;
	int sum = 0;
	while (i < n) {
		for (; i < n; i++) {
			if (map[v[i]] == 0)map[v[i]]++;
			else break;
		}

		index = i;
		sum += (index-pre-1)*((index-pre-1) + 1) - 2;
		pre = i;
		map.clear();
		map.resize(10);
		i++;
	}

}