#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void deleteNode(ListNode* node) {
			auto next = node->next;
			*node = *next;
			delete next;
	}
};
int main() {
	Solution s;
	ListNode *N1 = new ListNode(1);
	ListNode *N2 = new ListNode(2);
	N1->next = N2;
	ListNode *head = N1;
	s.deleteNode(head);
}