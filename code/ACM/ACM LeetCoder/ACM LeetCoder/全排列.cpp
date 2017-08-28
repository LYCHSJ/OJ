class Solution {
public:
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	void permutation(vector<int> &num, int begin, int end, vector<vector<int> > &vec)
	{
		if (begin == end)
			vec.push_back(num);
		if (begin < end)
		{
			for (int i = begin; i <= end; i++)
			{
				swap(num[begin], num[i]);
				permutation(num, begin + 1, end, vec);
				swap(num[begin], num[i]);
			}
		}
	}
	vector<vector<int> > permute(vector<int> &num) {
		int length = num.size();
		vector<vector<int> > vec;
		if (length == 0)return vec;
		permutation(num, 0, length - 1, vec);
		return vec;
	}
};