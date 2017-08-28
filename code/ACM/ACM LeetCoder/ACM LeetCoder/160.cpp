#include<iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode * p = headA;
		int lenA = 0;
		int lenB = 0;
		while (p != NULL) {
			lenA++;
			p = p->next;
		}
		p = headB;
		while (p != NULL) {
			lenB++;
			p = p->next;
		}
		ListNode * shortlist = lenA >= lenB ? headB : headA;
		ListNode * longlist = lenA >= lenB ? headA : headB;
		int longer = lenA >= lenB ? lenA : lenB;
		int shortter = lenA >= lenB ? lenB : lenA;
		while (longer != shortter) {
			longlist = longlist->next;
			longer--;
		}
		for (int i = 0; i<shortter; i++) {
			if (longlist == shortlist)return shortlist;
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		return NULL;
	}
};
int main() {
	Solution s;
	ListNode * node1 = new ListNode(1);
	ListNode * node2 = new ListNode(2);
	ListNode * node3 = new ListNode(3);
	ListNode * node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node4;
	node3->next = node4;
	cout<<s.getIntersectionNode(node1, node3)->val<<endl;
	return 0;
}