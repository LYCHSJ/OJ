#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tec;
int N, k;
int binarySearch_kth(int start,int end,int k,vector<int> vec) {
	if (k - 1 > end)return -1;
	if (start == end)return vec[start];
	int length = vec.size();
	vector<int> ret;
	int nmiddle = start;
	for (int i = start; i <=end; i++) {
		int middle = (start + end) / 2;
		if (vec[i] < vec[middle]) {
			ret.insert(ret.begin(), vec[i]);
			nmiddle++;
		}
		else ret.push_back(vec[i]);
	}
	int res= (k <= nmiddle)?binarySearch_kth(start, nmiddle, k,ret): binarySearch_kth(nmiddle + 1, end, k,ret);
	return res;
}
int main() {
	cin >> N >> k;
	while (N--) {
		int num;
		cin >> num;
		tec.push_back(num);
	}
	cout << binarySearch_kth(0,tec.size()-1,k,tec) << endl;
	return 0;
}