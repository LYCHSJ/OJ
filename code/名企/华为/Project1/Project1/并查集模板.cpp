#include<iostream>
#include<vector>	
using namespace std;
int MAXSIZE =10000;
vector<int> father(MAXSIZE, 0);
int n;
void makeSet() {
	for (int i = 1; i <= n; ++i)
		father[i] = 0;
	return;
}
//通过递归来进行查找
int find(int x) {
	//若当前节点的father=0,则为根
	if (!father[x]) return x;
	//否则检查其父节点
	return find(father[x]);
}
//将x和y所在的两个集合合并
void Union(int x, int y) {
	//分别找出x和y所在集合的代表
	int xf = find(x);
	int yf = find(y);
	//检查是否是同一个集合
	if (xf != yf)
		father[xf] = yf;
	return;
}
//路径压缩
/*
int find(int x) {
if (!father[x]) return x;
//路径压缩
father[x] = find(father[x]);
return father[x];
}
*/


int main() {

}