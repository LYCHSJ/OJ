#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int A;
	int ret=0;
	for (int i = 0; i < n; i++) {
		cin >> A;
		ret = ret^A;
	}
	if (ret == 0)cout << "Bob" << endl;
	else cout << "Alice" << endl;
}