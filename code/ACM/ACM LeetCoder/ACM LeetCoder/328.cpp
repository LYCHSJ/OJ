#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head)return head;
		ListNode *first = head;
		ListNode *second = head->next;
		ListNode *halfhead = head->next;
		while (second && second->next) {
			first = first->next = second->next;
			second = second->next = first->next;
		}
		first->next = halfhead;
		return head;
	}
};

int main() {

}