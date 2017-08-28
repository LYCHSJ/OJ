//��������
#include<iostream>
using namespace std;
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ����   
		quick_sort(s, i + 1, r);
	}
}
void qSort(int a[], int n) {
	int l = 0;
	int r = n - 1;
	quick_sort(a, l, r);
}
int main() {
	int a[] = { 8,6,7,5,3,9 };
	int n = 6;
	qSort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}