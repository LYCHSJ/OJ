#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sum(vector<int>);
int sum(vector<int> v) {
	int result = 0;
	for (auto &r : v) {
		result += r;
	}
	return result;
}

int main() {
	vector<int> v;
	int n;
	do{		
		cin >> n;
		v.push_back(n);
		//cout << "ok" << endl;
	} while (cin.get() != '\n');
	cout << sum(v) << endl;
	system("pause");
}