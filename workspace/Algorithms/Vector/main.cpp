#include"vector_func.h"



int main() {
	int a1[] = { 5,2,3,1 };
	vector<int> a(a1, a1 + 4);
	vector<int> b = sortArray(a);

	/*int a[][5] = { {1, 4, 7, 11, 15},
					{2, 5, 8, 12, 19},
					{3, 6, 9, 16, 22},
					{10, 13, 14, 17, 24},
					{18, 21, 23, 26, 30} };
	vector<vector<int>> V(5, vector<int>(5, 0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			V[i][j] = a[i][j];
		}
	}

	vector<vector<int>> V2(1, vector<int>(1, 0));
	V2[0][0] = -5;
	cout << searchMatrix(V2, 5) << endl;*/


	return 0;
}