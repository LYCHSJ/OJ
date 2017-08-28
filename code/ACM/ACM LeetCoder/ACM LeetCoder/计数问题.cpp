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
			//getline(cin,line);getline先读取cin中的内容，不会判断是否为空，只判断是否在之前读取过了，故v[0]为""
			v[i] = line;
		}

	}


}