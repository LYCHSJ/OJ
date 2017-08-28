#include<stdio.h>
typedef unsigned char       BYTE;
int main() {
	char a = 'a';
	FILE *p;
	p = fopen("D:\\Workspace\\data\\a", "a+");
	fprintf(p, a);
	BYTE * Payload = "abcdef";

	for (int j = 6; j < 11; j++) {
		char * filename;
		filename = *(BYTE *)Payload;
		filename++;
		printf("%02x ", *(BYTE *)Payload++);

	}
	
	return 0;
}