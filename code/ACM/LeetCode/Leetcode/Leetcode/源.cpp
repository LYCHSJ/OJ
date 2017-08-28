#include<iostream>
#include<vector>
using namespace std;
int L, F, D;
int T;
bool judge() {
	if (F > L)return false;
	if (D%L == 0||L%D==0)return true;
	int a = D;
	int b = L;
	int r = a%b;
	while (r) {
		a = b;
		b = r;
		r = a%b;
	}
	int c = L*D / b;//最小公倍数
	int count = 1;
	for (int step = D; step <= c; step +=D) {
		if (step - D + F > step/L*L) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> L >> F >> D;
		if (judge()) {
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}