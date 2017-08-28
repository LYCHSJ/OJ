#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int N = 100010;
int n, m, f[N];
map<string, int> MP;
char s[N];
//�����нڵ��father����0
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
	//�ֱ��ҳ�x��y���ڼ��ϵĴ���
	int xf = find(x);
	int yf = find(y);
	//����Ƿ���ͬһ������
	if (xf != yf)
		f[xf] = yf;
	return;
}
//stringӳ�䵽int
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
