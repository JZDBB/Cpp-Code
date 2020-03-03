#include<string>
using namespace std;

string LCS(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	if (n == 0 || m == 0) {
		return "";
	}else if (str1[m - 1] == str2[n - 1]) {
		char a = str1[m - 1];
		str1.pop_back();
		str2.pop_back();
		return LCS(str1, str2) + a;
	}else{
		string tr1, tr2, temp1, temp2;
		tr1 = str1;
		tr2 = str2;
		str1.pop_back();
		str2.pop_back();
		temp1 = LCS(str1, tr2);
		temp2 = LCS(tr1, str2);
		if (temp1.length() >= temp2.length()) {
			return temp1;
		}else{
			return temp2;
		}
	}
}