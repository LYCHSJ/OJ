#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int N;
	while(cin >> N){
		vector<string> v(N);
		string line;
		for (int i = 0; i != N; i++) {
			cin >> line;
			//getline(cin,line);getline�ȶ�ȡcin�е����ݣ������ж��Ƿ�Ϊ�գ�ֻ�ж��Ƿ���֮ǰ��ȡ���ˣ���v[0]Ϊ""
			v[i] = line;
		}

	}


}