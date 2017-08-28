#include<iostream>
#include<vector>
#include<string>
using namespace std;
int T;
string str;
string Decode(string in) {
	int count1 = 0;
	if (in[0] == '0') {
		count1 = 1;
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (in[i] == '1') {
				break;
			}
			count1++;
		}
	}

	int sum = 0;
	if (count1 == 1) {
		for (int i = 1; i <8; i++) {
			sum = sum * 2;
			sum += int(in[i]-'0');
		}
		string ret = to_string(sum);
		return ret;
	}
	else {
		for (int i = 0; i < count1; i++) {
			for (int j = i*8+2; j < i*8+8; j++) {
				if (i = 0) {
					j = count1 + 1;
					sum = sum * 2;
					sum += int(in[j] - '0');
				}
				else {
					sum = sum * 2;
					sum += int(in[j] - '0');
				}
			}
		}
		string ret = to_string(sum);
		return ret;
	}
}

int main() {
	string res;

	string _in;
	getline(cin, _in);

	res = Decode(_in);
	cout << res << endl;

	return 0;

}