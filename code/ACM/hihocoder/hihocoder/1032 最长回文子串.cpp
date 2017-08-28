#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int T;
const int N = 100000;
string manacher(string word) {
	char str[N];
	int f[N];
	str[0] = '$';
	int n = 1;
	for (int i = 0; i<word.size(); i++) {
		str[n++] = '#';
		str[n++] = word[i];
	}
	str[n++] ='#';
	str[n] = '@';
	int max = -1, t = 0;
	for (int i = 0; i <= n; i++) {
		if (max >= i)f[i] = min(f[2 * t - i], max - i);
		else f[i] = 0;
		while ((i - f[i] - 1>=0)&&str[i - f[i] - 1] == str[i + f[i] + 1])f[i]++;
		if (f[i] + i > max) {
			max = f[i] + i;
			t = i;
		}//
	}

	int ans=-1;
	int index = 0;
	for (int i = 0; i <= n; i++) {
		if (f[i] > ans) {
			ans = f[i];
			index = i;
		}
	}
	string ret;
	int j = index - ans;
	if (str[j] = '#') {
		j++;
	}
	for (; j <= index + ans; j = j + 2) {
		ret+=str[j];
	}
	//return ret;
	return ans;
}
int main()
{
	cin >> T;
	while (T--) {
		string word;
		cin >> word;


		cout << manacher(word)<< endl;
	}
	return 0;
}