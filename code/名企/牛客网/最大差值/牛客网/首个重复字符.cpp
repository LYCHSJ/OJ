#include<iostream>
#include<string>
#include<vector>
using namespace std;
class FirstRepeat {
public:
	char findFirstRepeat(string A, int n) {
		vector<int> v(256,0);
		char ret;
		for (int i = 0; i <n; i++) {
			if (v[int(A[i])]==0) {
				v[int(A[i])]++;
			}
			else {
				return ret=A[i];
			}
		}
		return ret=NULL;
	}
};
int main() {
	FirstRepeat s;
	string str = "qywyer23tdd";
	cout << s.findFirstRepeat(str, 11) << endl;
	return 0;
}