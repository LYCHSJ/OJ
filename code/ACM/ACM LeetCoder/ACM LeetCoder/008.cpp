#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		istringstream buffer(str);
		int number;
		buffer>>number;
		return number;
	}
};
