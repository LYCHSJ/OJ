#include <iostream>

int sum(int N);
int sum(int N){
	return ((1 + N)*N/2);
}

int main() {
	int N = 0;
	while (std::cin >> N){
		std::cout << sum(N) << std::endl;
	}
}