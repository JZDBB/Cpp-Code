#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// 633. Sum of Square Numbers (Easy)
bool judgeSquareSum(int c) {
	// 蛮力 时间复杂度 O(sqrt(n)) 事实上会快一些
	for (int i = 1; pow(i, 2) <= c/2; i++) {
		double diff = c - pow(i, 2);
		if (sqrt(diff) - int(sqrt(diff)) == 0) return true;
	}
	return false;

	// 双指针 时间复杂度 O(sart(n))
	int left = 0;
	int right = (int)sqrt(c);
	while (left < right) { // 相等情况
		long sum = pow(left, 2) + pow(right, 2); // 长整型防溢出 —— 64位编译系统：int占四字节，long占8字节，long数据范围变为：-2^63~2^63-1
		if (sum < c) left++;
		else if (sum > c)right--;
		else return true;
	}
	return false;

}

//167. 两数之和 II - 输入有序数组
vector<int> twoSum(vector<int>& numbers, int target) {
	// 双指针——削减搜索空间
	int index1 = 1, index2 = numbers.size();
	while (index1 < index2) {
		int sum = numbers[index1 - 1] + numbers[index2 - 1];
		if (sum == target) return vector<int>{index1, index2};
		else if (sum > target) index2--;
		else index1++;
	}
	return {};
}


char a[10] = { 'a', 'e', 'i', 'o', 'u' , 'A', 'E', 'I', 'O', 'U' };
vector<char> Vowels(a, a + 10);

// 345. 反转字符串中的元音字母
string reverseVowels(string s) {
	// me (42ms)
	int left = 0;
	int right = s.size()-1;
	while (left < right) {
		if (find(Vowels.begin(), Vowels.end(), s[left]) != Vowels.end()) {
			if (find(Vowels.begin(), Vowels.end(), s[right]) != Vowels.end()) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
			else right--;
		}
		else left++;
	}

	// 改进版 
	// 1.减少嵌套循环减少了一定时间 (32ms)
	// 2.减少数组find遍历改为简单判断，大概减少了一半时间。(16ms)
	// 3.将判断中的！=和&&分别改为==和||又减少了一定时间。(8ms)
	int left = 0;
	int right = s.size() - 1;
	bool flag1 = 0, flag2 = 0;
	while (left < right) {
		if (s[left] == 'a' || s[left] == 'o' || s[left] == 'e' || s[left] == 'i' || s[left] == 'u' || s[left] == 'A' || s[left] == 'E' || s[left] == 'I' || s[left] == 'O' || s[left] == 'U') {
			flag1 = 1;
		}
		else left++;
		if (s[right] == 'a' || s[right] == 'o' || s[right] == 'e' || s[right] == 'i' || s[right] == 'u' || s[right] == 'A' || s[right] == 'E' || s[right] == 'I' || s[right] == 'O' || s[right] == 'U') {
			flag2 = 1;
		}
		else right--;
		if (flag1&&flag2) {
			swap(s[left], s[right]);
			left++;
			right--;
			flag1 = flag2 = 0;
		}
	}

	return s;
}

int main() {
	

	return 0;
}