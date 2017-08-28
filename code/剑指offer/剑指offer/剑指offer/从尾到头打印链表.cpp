#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		//if (!head)return NULL;
		stack<int> sta;
		while (head) {
			sta.push(head->val);
			head = head->next;
		}
		vector<int> num;
		while (!sta.empty()) {
			num.push_back(sta.top());
			sta.pop();
		}
		return num;
	}
};
//µ›πÈ µœ÷
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		//if (!head)return NULL;
		vector<int> ret;
		if (head) {
			if (head->next)ret = printListFromTailToHead(head->next);
			ret.push_back(head->val);
		}

		return ret;
	}
};