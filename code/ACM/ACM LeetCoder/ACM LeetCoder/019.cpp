#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode ** t1 = &head, *t2 = head;
		for (int i = 1; i < n; i++) {
			t2 = t2->next;
		}
		while(!t2->next){
			t1 = &((*t1)->next);
			t2 = t2->next;
		}
		*t1 = (*t1)->next;
		return head;
	}
};
int main() {
	Solution s;
	ListNode *N1 = new ListNode(1);
	ListNode *N2 = new ListNode(2);
	N1->next = N2;
	ListNode *head = N1;
	s.removeNthFromEnd(head,2);
}