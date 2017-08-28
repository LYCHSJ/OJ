#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		vector<int> v(n,0);
		int count = 0;
		for (int i = 2; i < n; i++) {
			if (v[i] == 0) {
				count++;
				for (int k = 1; i*k < n; k++) {
					v[i*k] = 1;
				}
			}
		}
		return count;
	}

};

int main() {
	Solution s;
	int n = 100;
	cout<<s.countPrimes(n)<<endl;
	return 0;
}