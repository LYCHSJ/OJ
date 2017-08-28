#include<iostream>
#include<Windows.h>

int main() {
	const int Num = 100;

	for (int i = 0; i < 100; i++) {

		Sleep(200);
		double s = (double)i / Num * 100;
		std::cout << s << "%\r";
	}
	return 0;
}