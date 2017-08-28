#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty())return length;
		length = nums.size();
		vector<int>::iterator p = nums.begin();
		while(p!=nums.end()) {
			if (*p == val) {
				if (p == nums.end() - 1) {
					nums.erase(p); break;
				}
				std::copy(p + 1, nums.end(), p);
				vector<int>::iterator itend = nums.end()-1;
				nums.erase(itend);
			}
			else p++;
		}
		length = nums.size();
		return length;
	}
	/*比较好的方法
	int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(nums[i] == val)
            cnt++;
        else
            nums[i-cnt] = nums[i];
    }
    return nums.size()-cnt;
}
	*/
private:
	int length=0;
};

int main() {
	vector<int> nums = { 3,2,4,3 };
	Solution s;
	cout<<s.removeElement(nums,3)<<endl;
	return 0;
}