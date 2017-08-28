#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main() {
	int x = 0;
	stringstream buffer;
	buffer << x;
	string word = buffer.str();
	cout << word << endl;
	return 0;
}