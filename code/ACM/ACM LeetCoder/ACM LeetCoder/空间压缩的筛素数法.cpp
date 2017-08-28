#include<stdio.h>
#include<memory.h>

const int MAX = 100;
int prime[MAX / 3+1],pi;
int flag[MAX];

void GetPrime() {
	int i, j;
	pi = 0;
	memset(flag, false, sizeof(flag));
	for (i = 2; i < MAX; i++) {
		if (!(flag[i / 32] >> (i % 32) & 1)) {
			prime[pi++] = i;
			for (j = i; j < MAX; j += i)
				flag[j / 32] |= (1 << (j % 32));
		}
	}
}

void PrintArray() {
	for (int i = 0; i < pi; i++) {
		printf("%d ", prime[i]);
	}
}

int main() {
	printf("用位操作压缩后筛素数法求100内的素数\n");
	GetPrime();
	PrintArray();
	return 0;
}