#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
int BinarySearch_sorted(vector<int> vec, int K) {
	int start = 0, end = vec.size();
	while (start<=end) {
		int mid = start / 2 + end / 2;
		if (vec[mid] == K)return mid+1;
		else if (vec[mid] > K) {
			end = mid-1;
		}
		else {
			start = mid + 1;
		}
	}
	return -1;
}
int BinarySearch_unsorted(vector<int> vec, int K) {
	//交换mid左右时间复杂度O（N），和遍历一遍相同，简单起见就遍历一遍
	bool appear = false;
	int ans = 0;
	for (int i = 0; i < vec.size(); i++) {		
		if (vec[i] < K)ans++;
		if (vec[i] == K)appear = true;
	}
	if(!appear)return -1;
	return ans+1;
}
int main() {
	cin >> N >> K;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	//sort(vec.begin(),vec.end());
	//int ret = BinarySearch_sorted(vec, K);
	int ret = BinarySearch_unsorted(vec, K);
	cout << ret << endl;
	return 0;
}