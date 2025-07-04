#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mat{
	int h,w;
public:
	Mat(int height,int width):h(height),w(width)
, matrix(height, vector<int>(width, 0)) {
		num = cnt;
		cnt += 1;
	}
	int num;
	static int cnt;
	vector<vector<int>> matrix;
	friend istream& operator>> (istream& is, Mat& obj) {
		for (int i = 0; i < obj.matrix.size(); i++) {
			for (int j = 0; j < obj.matrix[0].size(); j++) {
				is >> obj.matrix[i][j];
			}
		}
		return is;
	}
	friend ostream& operator<< (ostream& os, const Mat& obj) {
		for (int i = 0; i < obj.matrix.size(); i++) {
			os << obj.matrix[i][0];
			for (int j = 1; j < obj.matrix[0].size(); j++) {
				os << " " << obj.matrix[i][j];
			}
			os << endl;
		}
		return os;
	}
	int sum() {
		int s = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				s += matrix[i][j];
			}
		}
		return s;
	}
	bool operator< (const Mat& other) {
		if (h * w != other.h * other.w) {
			return h * w < other.h* other.w;
		}
		return num > other.num;
	}
};
int Mat::cnt = 0;
bool comparator_1(Mat& a, Mat& b) {
	if (a.sum() != b.sum()) {
		return a.sum() < b.sum();
	}
	return a.num > b.num;
}
class comparator_2 {
public:
	bool operator() (const Mat& a, const Mat& b) {
		return a.num < b.num;
	}
};
int main()
{
	vector<Mat> m;
	m.push_back(Mat(2,2));
	m.push_back(Mat(3,4));
	m.push_back(Mat(2,2));
	cin >> m[0] >> m[1] >> m[2];
	sort(m.begin(),m.end());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_1);
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_2());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	return 0;
}
