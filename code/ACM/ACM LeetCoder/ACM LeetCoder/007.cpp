#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		stringstream buffer;
		buffer << x;
		string word = buffer.str();
		string result;
		if (x >= 0) {
			for (int i = word.size() - 1; i >= 0; i--) {
				result += word[i];
			}
		}
		else {
			result = "-";
			for (int i = word.size() - 1; i >0; i--) {
				result += word[i];
			}
		}
		stringstream output(result);
		__int64 oL_number;
		output >> oL_number;
		if (oL_number > 2147483647||oL_number<-2147483647)return 0;
		int o_number = oL_number;
		return o_number;
	}
};
int main() {
	Solution s;
	int a = 1000000003;
	int b = -321;
	cout << s.reverse(a) << endl;
	cout << s.reverse(b) << endl;
}