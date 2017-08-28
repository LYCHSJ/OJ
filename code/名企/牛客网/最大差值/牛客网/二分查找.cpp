#include<iostream>
#include<vector>
using namespace std;
class BinarySearch {
public:
	int getPos(vector<int> A, int n, int val) {
		int end = n-1;
		int start = 0;
		while (start < end) {
			int mid = (start + end) / 2;
			if (!(A[mid] ^ val))return mid;
			else if (A[mid] < val) {
				start =mid+1;
			}
			else end = mid-1;
		}
		return -1;
	}
};
int main() {
	BinarySearch s;
	vector<int> A = { 11,27,28,33 };
	cout << s.getPos(A, 4, 11) << endl;
}