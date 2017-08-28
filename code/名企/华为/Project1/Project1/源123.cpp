#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int u; int v;
	node(int a, int b) {
		u = a;
		v = b;
	}
};
bool nonmem_cmp(node &t1,node &t2)
{
	if (t1.u < t2.u)
		return true;
	return false;
}
int main() {
	int city, road;
	cin >> city >> road;
	vector<int>vec;
	vector<node>vea;
	int sum = 0;
	for (int i = 0; i < road; i++) {
		int u;
		int v;
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		node* Node = new node(u, v);
		vea.push_back(*Node);
	}
	sort(vea.begin(), vea.end(), nonmem_cmp);
	for (int i = 0;i < vea.size();i++){
		if (vec.empty()) {
			vec.push_back(vea[i].u);
			vec.push_back(vea[i].v);
			continue;
		}

		vector<int>::iterator resultu=find(vec.begin(), vec.end(), vea[i].u);
		vector<int>::iterator resultv = find(vec.begin(), vec.end(), vea[i].v);
		if (resultu == vec.end() && resultv == vec.end()) {
			sum++;
			vec.push_back(vea[i].u);
			vec.push_back(vea[i].v);
		}
		else if (resultu != vec.end() && resultv == vec.end()) {
			vec.push_back(vea[i].v);
		}
		else if (resultu == vec.end() && resultv != vec.end()) {
			vec.push_back(vea[i].u);
		}
	}
	int delta = city - vec.size();
	if (delta < 0)delta = 0;
	int qwe = sum + delta;
	cout << qwe << endl;
}