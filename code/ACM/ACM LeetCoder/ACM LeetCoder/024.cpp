#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode *node = head;
		ListNode *before = head;
		while (node&&node->next) {
			ListNode *tmp = node->next;
			node->next = node->next->next;
			tmp->next = node;
			if (before == head) {
				before = tmp; head = tmp;
			}
			else before->next = tmp;
			before = node;
			node = node->next;
		}
		return head;
	}
};

int main() {
	Solution s;
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	ListNode *newnode = s.swapPairs(node1);
	while (newnode) {
		cout << newnode->val << " ";
		newnode = newnode->next;
	}
	return 0;
}