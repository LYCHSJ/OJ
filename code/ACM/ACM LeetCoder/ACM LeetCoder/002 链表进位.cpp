#include<iostream>

using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* results=new ListNode(0);
		ListNode* p = results;
		int rise = 0;
		
		while(true){
			bool flag = false;
			int num = l1->val + l2->val+rise;
			p->val = num % 10;
			if ((num / 10) > 0) {
				rise = num / 10;
				flag = true;
			}
			else {
				rise = 0;
				flag = false;
			}
			l1->val = 0;
			l2->val = 0;
			if (l1->next != NULL) {
				l1 = l1->next;
				flag = true;
			}
			if (l2->next != NULL) {
				l2 = l2->next;
				flag = true;
			}
			if (flag)p->next = new ListNode(0);
			if (p->next == NULL)break;
			p = p->next;
		}
		
		return results;
	}
};

int main() {
	
	return 0;
}