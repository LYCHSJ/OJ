#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N = 100010;
int n, m, f[N];
map<string, int> MP;
char s[N];
//令所有节点的father等于0
void makeSet() {
	for (int i = 1; i <= n; ++i)
		f[i] = 0;
	return;
}

int find(int x) {
	int y = x;
	for (; x != f[x]; x = f[x]);
	return f[y] = x;
}
void Union(int x, int y) {
	//分别找出x和y所在集合的代表
	int xf = find(x);
	int yf = find(y);
	//检查是否是同一个集合
	if (xf != yf)
		f[xf] = yf;
	return;
}
//string映射到int
int read() {
	scanf("%s", s);
	if (MP.count(s)) return MP[s];
	MP[s] = ++m;
	f[m] = m;
	return m;
}

int main() {
	scanf("%d", &n);
	m = 0;
	int x, y, op;
	makeSet();
	while (n--) {
		scanf("%d", &op);
		x = find(read());
		y = find(read());
		if (op & 1) {
			puts(x == y ? "yes" : "no");
		}
		else {
			f[x] = y;
		}
	}
	return 0;
}
