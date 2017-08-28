#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long printout(long long num) {
	long long sum = 0;
	long long index = 1;
	while (num) {
		//sum *= 7;
		long long temp = num % 10;
		sum+= temp*index;
		index *= 7;
		num= num /10;


	}
	return sum;
}
int main() {
	long long num;
	cin >> num;
	cout << printout(num) << endl;
	return 0;
}