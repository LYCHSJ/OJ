#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int SegmentTree[40000];
int array[10000];
vector<int> vec;
struct TreeNode
{
	int val;
	int left=0, right=0;
	TreeNode(int x) {
		val = x;
	}
};
void build(int node,int left,int right) {
	if (left == right) {
		SegmentTree[node] = SegmentTree[node];
	}
	else{
		build(2*node, left, (left + right) / 2);
		build(2*node+1, (left + right) / 2 + 1, right);
		//回溯得到节点值
		if (SegmentTree[2*node] <= SegmentTree[2*node+1]) {
			SegmentTree[node] = SegmentTree[2*node];
		}
		else
			SegmentTree[node] = SegmentTree[node* 2 + 1];
	}
}
int query(int node, int left, int right, int queryleft, int queryright) {
	if (queryright<left || queryleft>right) return -1;
	if (left <= queryleft&&right >= queryright)return SegmentTree[node];
	int p1 = query(2 * node, left, (left + right) / 2,queryleft,queryright);
	int p2 = query(2 * node+1, (left + right) / 2+1, right, queryleft, queryright);
	return (p1 == -1 || p2 == -1)?p1 + p2 + 1:(p1 >= p2 ? p2 : p1);
}
void modify(int node, int left, int right, int p, int val) {
	if (p<left || p>right)return;
	if (p >= left&&p <= right)SegmentTree[node] = val;
	else {
		modify(node*2,left,(left+right)/2,p,val);
		modify(node*2+1, (left + right) / 2,right,p,val);
		SegmentTree[node] = min(SegmentTree[node*2], SegmentTree[node*2+1]);
	}
}
int main() {
	cin >> N;
	vector<TreeNode> point;
	for (int i = 0; i < N;i++){
		int val;
		cin >> val;
		vec.push_back(val);
	}
	build(1, 0, N-1);
	
}