#include<iostream>
#include<vector>
using namespace std;

template <typename Object>
class matrix
{
public:
	matrix(int rows, int clos) :array(int rows) {
		for (int i = 0; i < rows; i++) {
			array[i].resize(clos);
		}
	}

	const vector<Object> & operator[](int row) const {
		return array[row];
	}
	vector<Object> & operator[](int row) const {
		return array[row];
	}

	int numrows() const {
		return array.size();
	}
	int numclos() const{
		return numrows()?array[0].size():0;
	}

private:
	vector<vector<Object> > array;
};





int main() {
	matrix<int> A(5,9);
	cout << A.numrows() << endl;
	cout << A.numclos() << endl;
	return 0;
}