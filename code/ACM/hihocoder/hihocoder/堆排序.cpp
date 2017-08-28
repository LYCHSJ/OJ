#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int MAX = 20010;
int Heap[MAX];
int inheap[MAX];
int Size = 0;
map<string, int>last_visit;
void heapswap(int x, int y) {
	int a = Heap[x];
	Heap[x] = Heap[y];
	Heap[y] = a;
}
int heapUp(int x) {
	while (x >1) {
		int temp = x / 2;
		if (Heap[x] < Heap[temp]) {
			heapswap(x, temp);
			x = temp;
		}
		else {
			break;
		}
	}
	return x;
}
int heapDown(int x) {
	while (x<=Size/2) {
		int temp = x * 2;
		if (temp + 1 <=Size) {
			if (Heap[temp] > Heap[temp + 1]) {
				temp = temp + 1;
			}
			if (Heap[x] > Heap[temp]) {
				heapswap(x, temp);
				x = temp;
			}
			else {
				break;
			}
		}
	}
	return x;
}
void build(int a[],int n) {
	Size = n;
	for (int i = 1; i <= n; i++) {
		Heap[i] = a[i-1];
	}
	for (int i = n/2; i>= 1; i--) {
		heapDown(i);
	}
	return;
}
void insert(int key) {
	Size++;
	Heap[Size] = key;
	heapUp(Size);
	return;
}
int get_top() {
	return Heap[1];
}
void Delete(int x) {
	heapswap(x, Size);
	Size--;
	x = heapUp(x);
	x = heapDown(x);
	return;
}
int main() {
	int a[] = { 8,7,9,6,1,5,3};
	int n = 7;
	Size = n;
	build(a, n);
	for (int i = 0; i < Size; i++) {
		cout << Heap[i+1] <<" ";
	}
	cout << endl;
	insert(4);
	for (int i = 0; i < Size; i++) {
		cout << Heap[i + 1] << " ";
	}
	Delete(3);
	cout << endl;
	for (int i = 0; i < Size; i++) {
		cout << Heap[i + 1] << " ";
	}
}
