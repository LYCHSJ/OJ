#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
vector<string>lines;
vector<set<string> >dict;
set<string>fwords;
int searchword(string fword) {
	vector<int>counts;
	int count = 0;
	int linenum = -1;
	istringstream fs(fword);
	string fw;
	while (fs >> fw) {
		fwords.insert(fw);
	}
	for (int i = 0; i < dict.size(); i++) {
		count = 0;
		for (set<string>::iterator j = fwords.begin(); j != fwords.end(); j++) {
			if (find(dict[i].begin(), dict[i].end() ,*j) != dict[i].end())count++;
		}
		counts.push_back(count);
	}
	int maxcount=-1;
	int tarno = -1;
	for (int i = 0; i < dict.size(); i++) {
		if (maxcount < counts[i]) {
			maxcount = counts[i];
			tarno = i;
		}
	}
	return tarno;
}
int main() {
	int n, m;
	cin >> n >> m;
	dict.resize(n);
	string em;
	getline(cin, em);
	for (int i = 0; i < n;i++) {
		string line;
		getline(cin, line);
		lines.push_back(line);//
		string word;
		istringstream ss(line);
		while (ss >> word) {
			dict[i].insert(word);
		}
	}
	while (m--) {
		string fword;
		getline(cin,fword);
		cout << lines[searchword(fword)] << endl;
		fwords.clear();
	}
}