#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;     
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		this->head = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int n = 0;
		ListNode *q = head;
		while (q) {
			q = q->next; n++;
		}
		int index=rand() % n + 1;
		ListNode *p = head;
		while (--index != 0) {
			p = p->next;
		}
		return p->val;
	}
private:
	ListNode *head;
};

int main() {
	ListNode *head=new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s(head);
	cout << s.getRandom() << endl;
	return 0; 
}