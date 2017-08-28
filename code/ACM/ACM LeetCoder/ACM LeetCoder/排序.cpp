#include<iostream>
#include<stdlib.h>

//冒泡排序1
int BubbleSort(int* A, int n){
	while(true){
		for(int i=1;i<n;i++){
			if(A[j-1]>A[j]){
				Swap(A[j-1],A[j]);
			}
		}
	}
	
}

int BubbleSort11(int* A, int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(A[j-1]>A[j]){
				Swap(A[j-1],A[j]);
			}
		}
	}
	return A;
}

//冒泡排序2

void BubbleSort2(int* A, int n){
	int i,j;
	bool flag;
	i = n;
	flag = true;
	while(flag){
		flag = false;
		for(int i=0;i<n;i++){
			for(j=1;j<n-1;j++){
				Swap(A[j-1],A[j]);
				flag=true;
			}
		}
	}
}

//冒泡排序3

void BubbleSort3(int* A, int n){
	int i,j;
	bool flag;
	i = n;
	flag = n;
	while(flag){
		flag = false;
		for(int i=1;i<n;i++){
			if(A[i-1]>A[i]){
				Swap(A[i-1],A[i]);
				flag=i;
			}
		}
	}
}

//直接插入排序

void InsertSort(int* A, int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=i-1;j>=0 && a[j]>a[j+1];j--){
			Swap(a[i],a[j+1])
		}
	}
}

//希尔排序

void shellsort1(int* a, int n){
	int i,j,gap;
	for(gap=n/2;gap>0;gap/=2)
		for(i=0;i<gap;i++){
			for(j=i+gap;j<n;j+=gap){
				if (a[j]<a[j-gap]){
					int temp=a[j];
					int k=j-gap;
					while(k>=0 && a[k]>temp){
						a[k+gap]=a[k];
						k -= gap;
						
					}
					a[k+gap]=temp;
				}
			}
		}
}