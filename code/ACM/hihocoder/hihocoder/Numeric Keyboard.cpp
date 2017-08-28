#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int K;
int keyboardMax(int K) {
	stack<int> s;
	int ret=0;
	while (K) {
		int tmp = K % 10;
		s.push(tmp);
		K /= 10;
	}
	int pre = 0;
	while (!s.empty()) {
		if (s.top() % 3 != 0&&) {
			ret = ret * 10 + s.top();
			s.pop();
		}
		else {

		}
	}
}
int main() {
	cin >> K;
	cout << keyboardMax(K) << endl;
	return 0;
}