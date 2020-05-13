#include"interview_func.h"

// 面试题45. 把数组排成最小的数
static bool smaller(int num1, int num2) {
	int n = num1;
	int bit1 = 0; int bit2 = 0;
	while (n) { bit1++; n /= 10; }
	n = num2;
	while (n) { bit2++; n /= 10; }
	if (num2 == 0) bit2 = 1;
	if (num1 == 0) bit1 = 1;
	long long x = num2 + num1 * pow(10, bit2);
	long long y = num1 + num2 * pow(10, bit1);
	return x < y;
}
string int2string(int i) {
	if (i == 0) return "0";
	string res = "";
	while (i) {
		res.insert(res.begin(), i % 10 + '0');
		i /= 10;
	}
	return res;
}
string minNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end(), [](int &num1, int &num2) {
		return smaller(num1, num2);
	});
	string res = "";
	for (int i : nums) {
		res += int2string(i);
	}
	return res;
}

//public:
//	string minNumber(vector<int>& nums) {
//		vector<string> strs;
//		string res;
//		for (auto num : nums)
//			strs.push_back(to_string(num));
//		sort(strs.begin(), strs.end(), compare);
//		for (auto str : strs)
//			res += str;
//		return res;
//	}
//private:
//	static bool compare(const string &a, const string &b)
//	{
//		return a + b < b + a;
//	}