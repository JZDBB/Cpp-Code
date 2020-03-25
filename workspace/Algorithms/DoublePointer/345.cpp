#include"doublePointer.h"

// 345. 反转字符串中的元音字母
string reverseVowels(string s) {
	// me (42ms)
	int left = 0;
	int right = s.size() - 1;
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
	left = 0;
	right = s.size() - 1;
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