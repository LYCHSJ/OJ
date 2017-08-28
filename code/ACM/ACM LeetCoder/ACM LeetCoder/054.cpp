#include<iostream>
#include<vector>
using namespace std;
struct node {
	int m;
	int n;
	node(int x, int y) {
		m = x;
		n = y;
	}
};
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty())return ret;
		int m=matrix.size()-1;
		int n = matrix[0].size()-1;
		node *node1 = new node(0, 0);
		node *node2 = new node(0, n);
		node *node3 = new node(m, 0);
		node *node4 = new node(m, n);
		int i = 0;
		int j = 0;
		while (node1->m <= node4->m&&node1->n <= node4->n&&node2->m <= node3->m&&node2->n >= node3->n) {
			//i=node1->m;j=node1->n;
			if (j <= node2->n) {
				//i= node1->m;j<=node2->n
				while (j <= node2->n) {
					ret.push_back(matrix[i][j]) ;
					j++;
				}
				j--;
				node1->m++;
				node1->n++;
				i++;
			}
			else {
				break;
			}
			if (i <= node4->m) {
				//j=node2->n;i<=node4->m;
				while (i <= node4->m) {
					ret.push_back(matrix[i][j] );
					i++;
				}
				i--;
				node2->m++;
				node2->n--;
				j--;
			}
			else {
				break;
			}
			if (j >= node3->n) {
				//i=node4->m;j>=node3->n;
				while (j >= node3->n) {
					ret.push_back(matrix[i][j]);
					j -- ;
				}
				j++;
				node4->m--;
				node4->n--;
				i--;
			}
			else {
				break;
			}
			if (i >= node1->m) {
				//j=node3->n;i>=node1->m;
				while (i >= node1->m) {
					ret.push_back( matrix[i][j]) ;
					i--;
				}
				i++;
				node3->m--;
				node3->n++;
				j++;
			}
			else {
				break;
			}
		}
		return ret;
	}
};
int main() {
	Solution s;
	vector<vector<int>> v{ {1,2,3,4}};
	vector<int> ret = s.spiralOrder(v);
	for (int i = 0; i < ret.size();i++) {
		cout << ret[i] << " ";
	}
}