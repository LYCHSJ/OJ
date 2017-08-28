#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 1)return 1;
		else return 2 * jumpFloorII(number - 1);
	}
};