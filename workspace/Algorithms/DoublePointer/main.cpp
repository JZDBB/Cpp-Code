#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#include"doublePointer.h"


int main() {
	/*string a1[4] = { "ale", "apple", "monkey", "plea" };
	vector<string> a(a1, a1 + 4);
	string m = findLongestWord("abpcplea", a);*/
	int a1[] = { 1,1,1,2,2,3 };
	vector<int> a(a1, a1 + 6);
	int m = removeDuplicates2(a);

	return 0;
}