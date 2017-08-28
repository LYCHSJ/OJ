#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int arraryS[100000];
vector<int> vec;
struct Node {
	int left, right; //区间信息
	int data;        //数据域
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
	//判定当前节点区间是否包含在更新区间范围内
	if (left <= segmentTree[node].left && right >= segmentTree[node].right) {
		return segmentTree[node].data; //返回数据域
	}
	//询问子区间，没有子区间则退出，不往下递归查询    
	if (segmentTree[node].left == segmentTree[node].right) return 0;//返回无意义数据域
	//更新返回域
	int ret=0;
	ret += query(node * 2, left, right);
	ret += query(node * 2 + 1, left, right);
	return ret;
}

void update(int node, int left, int right, int value) {//从1节点开始DFS
	if (left > segmentTree[node].right || right < segmentTree[node].left)
		return; //判定当前节点区间是否与更新区间有交集
				//判定当前节点区间是否包含在更新区间范围内
	if (left<= segmentTree[node].left && right >= segmentTree[node].right) {
		segmentTree[node].data = value; //更新数据域
		return;
	}
	//更新子区间
		update(node * 2, left, right, value);
		update(node * 2 + 1, left, right, value);
	//更新数据域
		segmentTree[node].data = segmentTree[node*2].data+segmentTree[node*2+1].data;

   
 //根据子节点信息更新数据域
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