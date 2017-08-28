#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *removeElements(ListNode *head, int val)
	{
		ListNode **list = &head;

		while (*list != nullptr)
		{
			if ((*list)->val == val)
			{
				*list = (*list)->next;
			}
			else
			{
				list = &(*list)->next;
			}
		}

		return head;
	}
};
int main() {
	Solution s;
	ListNode *node1 = new ListNode(0);
	ListNode *node2 = new ListNode(0);
	ListNode *node3 = new ListNode(1);
	node1->next = node2;
	node2->next = node3;
	ListNode * ptr=s.removeElements(node1,1);
	while (ptr) {
		cout << ptr->val << endl;
		ptr = ptr->next;
	}
	return 0;
}