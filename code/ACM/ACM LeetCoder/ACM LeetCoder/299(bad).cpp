#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		vector<char> v;
		int lens = secret.size();
		int leng = guess.size();
		vector<int> flags(lens, 0);
		vector<int> flagg(leng, 0);
		for (int i = 0; i < secret.size(); i++) {
			v.push_back(secret[i]);
		}
		for (int i = 0; i < guess.size()&&i<secret.size(); i++) {
			if (v[i] == guess[i]) {
				bulls++;
				flags[i] = 1;
				flagg[i] = 1;
			}
		}
		for (int i = 0; i < secret.size(); i++) {
			for (int j = 0; j < guess.size(); j++) {
				if (flags[i] == 1 || flagg[j] == 1)continue;
				if (guess[j] == v[i]) { cows++; flags[i] = 1; flagg[j] = 1; }
			}
		}
		string answer;
		stringstream ss;
		ss << bulls << "A" << cows << "B";
		ss >> answer;
		return answer;
	}

private:
	int bulls = 0;
	int cows = 0;
};

int main() {
	Solution s;
	string secret = "1234";
	string guess = "0111";
	cout<<s.getHint(secret, guess)<<endl;
	return 0;
}