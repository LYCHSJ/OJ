#include<iostream>
#include<string>
using namespace std;
int sumOfErase(string text) {
	int len = text.size();
	int ret = 0;
	int contilenA = 0;
	int contilenB = 0;
	int contilenC = 0;
	string textA=text;
	string textB=text;
	string textC = text;
	for (int i = 0; i < len; i++) {
		textA.insert(textA.begin() + i, 'A');
		textB.insert(textB.begin() + i, 'B');
		textC.insert(textC.begin() + i, 'C');
		char tmpA = textA[0];
		char tmpB = textB[0];
		char tmpC = textC[0];
		int retA = 0;
		int retB = 0;
		int retC = 0;
		for (int j = 1; j < len + 1;j++) {
			if (tmpA == textA[j])contilenA++;
			else {
				tmpA = textA[j];
			}
			if (tmpB == textB[j])contilenB++;
			else {
				tmpB = textB[j];
			}
			if (tmpC == textC[j])contilenC++;
			else {
				tmpC = textC[j];
			}

		}
		int tmp=0;
		if(contilen>0)text.erase(i - contilen,contilen);
		tmp += contilen+1;
		tmp+=sumOfErase(text);


		if (tmp > ret)ret = tmp;

		textA.clear();//textABC 循环控制条件
		textA = text;
		textB.clear();
		textB = text;
		textC.clear();
		textC = text;
	}
	return ret;
}
int sumanderase(string text) {
	int ret = 0;
	int contilen = 1;
	int tmp = text[0];
	string::iterator it = text.begin();
	it++;
	while(it!=text.end()) {
		if (tmp == *it) {
			contilen++;
			it++; 
		}
		else if (contilen > 1) {
			it=text.erase(distance() - contilen, contilen);
			ret += contilen;
			ret += sumanderase(text);
			contilen = 1;
		}

	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	string text;
	while (cin >> text) {
		cout << sumOfErase(text) << endl;
	}
	return 0;
}