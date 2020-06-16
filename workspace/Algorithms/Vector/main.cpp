#include"vector_func.h"

struct point {
	int x;
	int y;
};


int main() {
	//int a1[] = { 28,59,91,27,32,43,65,84,36,30 }; // { 8,9,1,7,2,3,5,4,6,0 };
	//vector<int> a(a1, a1 + 10);
	//vector<int> b = sortArray(a);

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

	/*vector<point> P;
	point p1 = { 1, 3 };
	point p2 = { 4, 3 };
	point p3 = { 1, 6 };
	point p4 = { 3, 7 };
	point p5 = { 2, 4 };
	point p6 = { 5, 8 };
	P.push_back(p1);
	P.push_back(p2);
	P.push_back(p3);
	P.push_back(p4);
	P.push_back(p5);
	P.push_back(p6);
	sort(P.begin(), P.end(), 
		[](point &o1, point &o2) {
		return o1.x > o2.x || (o1.x == o2.x && o1.y > o2.y);
	});*/
	
	/*vector<int> m = { 2, 2, 2, 1, 2, 2, 1, 2, 2, 2 };
	int a = numberOfSubarrays(m, 2);*/

	/*vector<int> m = { 7,5,6,4 };
	int a = reversePairs(m);*/

	/*vector<int> m = { 1, 2, 3 };
	vector<vector<int>> a = permute(m);*/

	/*vector<int> m = { 2,3,4,2,6,2,5,1 };
	vector<int> a = maxInWindows(m, 3);*/

	int a = -2147483649;
	cout << a;


	vector<int> b;

	return 0;
}