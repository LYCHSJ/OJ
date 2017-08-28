#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		v = nums;
		for (int i = nums.size(); i > 0; i--) {
			total *= i;
		}
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		if (v.empty())return v;
		for (int i = turn; i !=0; i--) {
			if (j == 0)j = v.size()-1;
			//swap(v[j],v[j+1]);
			int tmp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = tmp;
			j--;
		}
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		if (v.empty())return v;
		srand((unsigned)time(NULL));
		turn = rand() % total;
		j = 0;
		for (int i = 0; i < turn; i++) {
			if (j + 1 == v.size())j = 0;
			//swap(v[j],v[j+1]);
			int tmp = v[j];
			v[j] = v[j + 1];
			v[j + 1] = tmp;
			j++;
		}
		return v;
	}
private:
	vector<int> v;
	int turn=0;
	int total=1;
	int j;
};

int main() {
	vector<int> num = { 1,2,3,4,5,6,7,8,9,10,11 };
	Solution *s=new Solution(num);
	vector<int>ret = s->shuffle();
	for (auto item : ret) {
		cout << item << " ";
	}
	cout << endl;
	vector<int> origin = s->reset();
	for (auto item : origin) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}