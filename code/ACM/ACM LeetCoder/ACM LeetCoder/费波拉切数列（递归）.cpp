#include <iostream>
int func(int N);
int func(int N) {
	int result = 0;
	if (N > 1)return result = func(N - 1) + func(N - 2);
	else if (N == 1)return result = 1;
	else
	{
		return result = 0;
	}

}
int main() {
	int N = 0;
	while (std::cin >> N){
		if (N >= 0 && N <= 40) {
			std::cout << func(N) << std::endl;
		}

	}
	system("pause");
}