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
//ͨ���ݹ������в���
int find(int x) {
	//����ǰ�ڵ��father=0,��Ϊ��
	if (!father[x]) return x;
	//�������丸�ڵ�
	return find(father[x]);
}
//��x��y���ڵ��������Ϻϲ�
void Union(int x, int y) {
	//�ֱ��ҳ�x��y���ڼ��ϵĴ���
	int xf = find(x);
	int yf = find(y);
	//����Ƿ���ͬһ������
	if (xf != yf)
		father[xf] = yf;
	return;
}
//·��ѹ��
/*
int find(int x) {
if (!father[x]) return x;
//·��ѹ��
father[x] = find(father[x]);
return father[x];
}
*/


int main() {

}