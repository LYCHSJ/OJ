#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> v(k,0);
		int count = 1;
		int ncount = n;
		for (int x = 0; x < k; x++) {
			count *= ncount;
			ncount--;
		}
		vector<vector<int>> ret(count,v);
		int j = n;
		while(j >0) {
			int i = k - 1;
			while( i >=0) {
				v[i] = j;
				j--;
				i--;
				ret[count--] = v;
				combine(j, i);
			}
		}

		return ret;
	}

};