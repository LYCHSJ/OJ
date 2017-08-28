#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
 num2
*
 num1
*/
void calculate(vector<int> num1, vector<int> num2) {
	vector<int> result(num1.size() + num2.size(), 0);
	for (int i = 0; i <num1.size(); i++) {
		for (int j =0; j<num2.size(); j++) {
			int sum = num1[i] * num2[j];
			result[i + j] += sum;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		while (result[i] > 10) {
			int carry = result[i] /10;
			result[i+1] += carry;
			result[i] %= 10;
		}
	}
	reverse(result.begin(), result.end());
	int start = 0;
	for (; start < result.size(); start++) {
		if (result[start] != 0)break;
	}
	for (; start < result.size(); start++) {
		cout << result[start];
	}
}
int main() {
	vector<int> num1, num2;
	string s_num1,s_num2;
	cin >> s_num1 >> s_num2;
	for (int i = s_num1.size()-1; i >=0 ; i--) {
		num1.push_back(s_num1[i] - '0');
	}
	for (int i = s_num2.size()-1; i >=0 ; i--) {
		num2.push_back(s_num2[i] - '0');
	}
	calculate(num1,num2);
}