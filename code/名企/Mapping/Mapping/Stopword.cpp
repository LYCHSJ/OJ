#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

class Stopword{
public:
	vector<string> stopword_init() {
		fstream stopword_text("D:\\stopword.txt");
		stringstream stopword;
		stopword << stopword_text.rdbuf();
		string word;
		while (stopword >> word) {
			stopword_bin.push_back(word);
		}
		return stopword_bin;
	}
private:
	vector<string> stopword_bin;
};