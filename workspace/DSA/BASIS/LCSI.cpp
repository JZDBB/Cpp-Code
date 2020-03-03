#include<string>
#include<math.h>
#include<iostream>
using namespace std;

int LCSI(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	if (m == 0 || n == 0) return 0;
	int **arr;
	arr = new int *[n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = new int[m + 1];
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0 || j == 0) {
				arr[i][j] = 0;
			} else if (str1[j-1] == str2[i-1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}else {
				arr[i][j] = arr[i - 1][j] >= arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
			}
		}
	}
	return arr[n][m];
}