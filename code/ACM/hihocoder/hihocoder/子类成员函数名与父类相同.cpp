#include<iostream>
using namespace std;
class A {
public:
	void func() {
		cout << "A" << endl;
	}
};
class B :public A {
public:
	void func() {
		cout << "B" << endl;
	}
};
int main() {
	A a;
	A * ptr;
	B b;
	a.func();
	b.func();
	ptr = &b;
	ptr->func();
	B *ptrb = &b;
	ptrb->func();
}