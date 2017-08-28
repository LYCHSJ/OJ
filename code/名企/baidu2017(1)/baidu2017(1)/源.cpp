#include<iostream>
#include<string>
using namespace std;
class solution {
public:
	void correctWord(string str) {
		int len = str.size();
		if (end !=NULL) {
			if(end == str[0])result = "Yes";
			else result = "No";
		}
		end = str[len - 1];
	}
	string askresult() {
		return result;
	}
private:
	char end=NULL ;
	string result = "";
};
int main()
{
	string str;
	int n;
	solution s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s.correctWord(str);
	}
	cout << s.askresult() << endl;
	return 0;
}