#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

class textPredeal {
public:
	vector<string> bin_init() {
		ifstream in("D:\\Text.txt");
		stringstream text;
		text << in.rdbuf();
		string word;
		while (text >> word) {
			int n = 0;
			while (n < k) {
				bin[n].push_back(word);
				text >> word;
				if (word == "")break;
				n++;
			}
		}
	}
	void setK(int k) {
		this->k = k;
	}
private:
	vector<vector<string> > bin;
	int k;
};