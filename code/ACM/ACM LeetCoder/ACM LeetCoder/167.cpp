#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {

		int middle = numbers.size() / 2;
		if (target == 2*numbers[middle]) {
			if (numbers[middle] == numbers[middle - 1]) {
				no.push_back(middle - 1+1);
				no.push_back(middle+1);
			}
			else if(numbers[middle] == numbers[middle + 1]) {
				no.push_back(middle+1);
				no.push_back(middle+1+1);
			}
			else loop(0, middle, numbers, target);
		}
		if (target > 2 * numbers[middle]) {
			loop(middle, numbers.size() - 1, numbers, target);
		}
		if (target < 2 * numbers[middle]) {
			loop(0, middle, numbers, target);
		}
		return no;
	}
	void loop(int left, int right,vector<int> numbers,int target) {
		int i=0;
		int j=0;
		for (i = left; i < right; i++) {
			j = 0;
			while (j < numbers.size()) {
				if (i == j) {
					j++; continue;
				}
				if (target == numbers[i] + numbers[j]) {
					if (i < j) { no.push_back(i+1); no.push_back(j+1); }
					else { no.push_back(j+1); no.push_back(i+1); }
					return;
				}
				j++;
			}
		}

	}
private:
	vector<int> no;
};
int main() {
	Solution s;
	int target = 6;
	vector<int> v = { 2,3,4 };
	vector<int> no=s.twoSum(v, target);
	cout << no[0] << no[1] << endl;
	return 0;
}