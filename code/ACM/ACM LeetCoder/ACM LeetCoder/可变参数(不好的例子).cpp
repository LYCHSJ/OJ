#include<stdio.h>
#include<stdarg.h>

void simple_va_fun(int start, ...) {
	va_list arg_ptr;
	int nArgValue = start;
	int nArgCount = 0;
	va_start(arg_ptr, start);
	do {
		++nArgCount;
		printf("�������������ˣ����ӵĲ���Ϊ%d", nArgValue);
		nArgValue = va_arg(arg_ptr, int);
	} while (nArgValue != -1);
	va_end(arg_ptr);
}

int main() {
	simple_va_fun(100, -1);
	simple_va_fun(100, 98, -1);
	return 0;
}