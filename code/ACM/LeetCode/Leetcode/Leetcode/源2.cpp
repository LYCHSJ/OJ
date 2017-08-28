#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string sortDA(string s) {
	int i = 0;
	int j = 0;
	while(i<s.size()-1) {
		if (char(s[i]) < 'a') {
			j = i;
			while (j<s.size()) {
				if (char(s[j]) >= 'a') {
					break;
				}
				j++;
			}
			swap(s[i], s[j]);
		}
		i++;
	}
	return s;
}
int main() {
	string s;
	s = "AkleBiCeilD";
	cout<<sortDA(s)<<endl;
}