#include<iostream>
#include<list>
#include<stack>
using namespace std;
class MinStack {
	stack<int> instack;
	list<int> order;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		instack.push(x);
		if (instack.empty() && order.empty()) {
			order.push_back(x);
		}
		else {
			if (x>order.back())order.push_front(x);
			else order.push_back(x);
		}

	}

	void pop() {
		if(instack.top()==order.back())order.pop_back();
		else order.pop_front();
		instack.pop();
	}

	int top() {
		return instack.top();
	}

	int getMin() {
		if (instack.empty())return NULL;		
		return order.back();
	}
};
int main() {
	MinStack mystack = new MinStack();
	mystack.push(1);
	mystack.push(2);
	mystack.pop();
	cout << mystack.top() << endl;
	cout << mystack.getMin()<<endl;
	return 0;
}