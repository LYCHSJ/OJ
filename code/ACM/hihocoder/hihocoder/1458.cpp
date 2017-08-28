#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<int> order;
	stack<char> sym;
	int x, y;
	vector<string> ret(str.size(),"");
	for (int i = 0; i < str.size(); i++) {
			order.push(i);
			sym.push(str[i]);
		if (sym.top()==')') {
			sym.pop();
			sym.pop();
			y = order.top()+1;
			order.pop();
			x = order.top()+1;
			order.pop();
			ret[x] = to_string(x) + " " + to_string(y);
		}
	}
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] != "")cout << ret[i] << endl;
	}
	return 0;
}