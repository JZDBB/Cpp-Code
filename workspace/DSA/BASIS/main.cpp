#include<iostream>
#include<string>
using namespace std;

string LCS(string str1, string str2);
int LCSI(string str1, string str2);

int main() {
	string str1, str2;
	str1 = "Education";
	str2 = "advance";
	cout << LCSI(str1, str2) << endl;

	return 0;
}
