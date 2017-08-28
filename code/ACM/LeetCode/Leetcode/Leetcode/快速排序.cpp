//快速排序
#include<iostream>
using namespace std;
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用   
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