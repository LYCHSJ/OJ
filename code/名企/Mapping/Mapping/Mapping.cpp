#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Solution {
public:
	bool Mapping(string s) {
		int grouplen = 2;
		int binlen=6;
		bitgroup = divideToBitGroup(s, grouplen);//bit分组
		bin=divideToBin(s, binlen,grouplen);//bin分组

		sequence = makeSequence(bitgroup, bin);

		cout << sequence << endl;
		if (sequence != "")return true;
		else return false;
	}

	vector<int> divideToBitGroup(string s,int length) {
		while (s.size() % length) {
			s += "0";
		}
		int i = 0;
		vector<string> subgroup_s;//存储bit的string分组
		vector<int> subgroup_i;//存储bit的int分组
		while (i != s.size()) {
			string tmp(s, i, length);
			subgroup_s.push_back(tmp);
			i = i + length;
		}
		for (int j = 0; j < subgroup_s.size(); j++) {
			int strtoint = 0;
			for (i = length-1; i >= 0; i--) {
				strtoint += (int(subgroup_s[j][i]) - 48)*pow(2, length-1 - i);
			}
			subgroup_i.push_back(strtoint);
		}
		return subgroup_i;
	}
	vector<vector<string> > divideToBin(string s, int binlen,int grouplen) {
		int i = 0;
		int j = 0;
		vector<string> su;
		int groupcount = pow(2, grouplen);
		vector<vector<string> > subgroup(groupcount,su);
		while (j != directory.size() && subgroup[i].size() != binlen) {
			subgroup[i].push_back(directory[j]);
			if (subgroup[i].size() == binlen)i ++;
			j++;
		}
		return subgroup;
	}
	string makeSequence(vector<int> bitgroup, vector<vector<string> > bin){
		string sequence;
		for (int i = 0; i < bitgroup.size(); i++) {
			sequence += bin[bitgroup[i]][0]+" ";
		}
		return sequence;
	}
private:
	vector<vector<string> > bin;
	vector<int> bitgroup;
	string sequence="";
	vector<string> directory
	{ "We", "want", "to", "enable" ,"a" ,"pair" ,"of", "communicating" ,"users" ,"to" ,"exchange",
		"secret" ,"messages" ,"while" ,"hiding","the", "fact" ,"that" ,"secret"
		,"communication" ,"is" ,"taking" ,"place"};
};
string readbinfile(ifstream &coverfile) {
	string text;
	getline(coverfile, text);
	cout << text;
	istringstream line(text);
	string word;
	string ret;
	int count=0;
	while (line >> word) {
		count++;
		if (word == "<epsilon>") {
			cout << count << endl;
			//mapping;
		}
	}
	return ret;
}
int main() {
	Solution s;
	string str="1110010011110001010001";
	//cout << "Mapping finished?" << s.Mapping(str) << endl;
	ifstream coverfile("print.txt");
	readbinfile(coverfile);
	return 0;
}