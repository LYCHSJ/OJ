#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int arraryS[100000];
vector<int> vec;
struct Node {
	int left, right; //������Ϣ
	int data;        //������
}   segmentTree[400000];
void build(int node, int left, int right) {
	segmentTree[node].left = left;
	segmentTree[node].right = right;
	if (left == right) {
		segmentTree[node].data = arraryS[left];
		return;
	}
	int mid = (left + right) / 2;
	build(node * 2, left, mid);
	build(node * 2 + 1, mid + 1, right);
	segmentTree[node].data = segmentTree[node * 2].data + segmentTree[node * 2 + 1].data;
	return;
}

int query(int node, int left, int right) {
	//�ж���ǰ�ڵ������Ƿ�����ڸ������䷶Χ��
	if (left <= segmentTree[node].left && right >= segmentTree[node].right) {
		return segmentTree[node].data; //����������
	}
	//ѯ�������䣬û�����������˳��������µݹ��ѯ    
	if (segmentTree[node].left == segmentTree[node].right) return 0;//����������������
	//���·�����
	int ret=0;
	ret += query(node * 2, left, right);
	ret += query(node * 2 + 1, left, right);
	return ret;
}

void update(int node, int left, int right, int value) {//��1�ڵ㿪ʼDFS
	if (left > segmentTree[node].right || right < segmentTree[node].left)
		return; //�ж���ǰ�ڵ������Ƿ�����������н���
				//�ж���ǰ�ڵ������Ƿ�����ڸ������䷶Χ��
	if (left<= segmentTree[node].left && right >= segmentTree[node].right) {
		segmentTree[node].data = value; //����������
		return;
	}
	//����������
		update(node * 2, left, right, value);
		update(node * 2 + 1, left, right, value);
	//����������
		segmentTree[node].data = segmentTree[node*2].data+segmentTree[node*2+1].data;

   
 //�����ӽڵ���Ϣ����������
	return;
}

int main() {
	int N, M;
	cin >> N>>M;
	for (int i = 1; i <= N; i++) {
		cin >> arraryS[i];
	}
	build(1, 1, N);
	char Q; int c; int r;
	while (M--) {
		cin>>Q>>c>>r;
		if (Q == 'Q')cout<<query(1, c - r, c + r)<<endl;
		if (Q == 'C') {
			update(1,c,c ,arraryS[r]);
			update(1,r,r, arraryS[c]);
		}
	}
}