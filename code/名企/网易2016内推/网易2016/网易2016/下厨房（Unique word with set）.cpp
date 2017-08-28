#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string text;
	set<string>item;
	getchar();//Юќзп'\n'
	for (int i = 0; i < n; i++) {
		getline(cin, text);
		istringstream line(text);
		string word;
		while (line >> word) {
			item.insert(word);
		}
	}
	cout << item.size() << endl;
}