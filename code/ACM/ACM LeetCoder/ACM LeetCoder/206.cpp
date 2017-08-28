#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *result=NULL;
		if (head == NULL)return result;
		if (head->next == NULL)return head;
		ListNode *p=head->next;
		ListNode *q=head;
		q->next = NULL;
		while (true) {
			ListNode *tmp;
			tmp= p->next;
			p->next = q;
			q = p;
			if(tmp!=NULL)p = tmp;
			else break;
		}
		return result=q;
	}
};

int main() {
	Solution s;
	ListNode *N1 = new ListNode(1);
	ListNode *N2 = new ListNode(2);
	N1->next = N2;
	ListNode *head = N1;
	s.reverseList(head);
}