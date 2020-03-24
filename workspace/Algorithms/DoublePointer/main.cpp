#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// 633. 平方数之和
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


// 680. 验证回文字符串 Ⅱ 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
bool isPalindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])  return false;
	}
	return true;
}

bool validPalindrome(string s) {
	// 判断回文字符串 I
	/*int left = 0;
	int right = s.size() - 1;
	while (left <= right) { // <= 需注意
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;*/

	// 判断回文字符串 I —— me
	// 问题：如何判断删掉双指针中哪一个所指的元素
	/*int left = 0;
	int right = s.size() - 1;
	bool flag = 0;
	while (left <= right) {
		if (s[left] != s[right]) {
			if (flag) return false;
			if (s[left + 1] == s[right]) { // 错误在于：先判断的先删除，没有和后面一起结合考虑
				flag = 1;
				left++;
			} else if (s[left] == s[right - 1]) {
				flag = 1;
				right--;
			}
			else return false;
		}
		left++;
		right--;
	}
	return true;*/

	// 改正版
	// 解决方法：两边都删除看看——不过这个方法需要判断两次，可能耗费时间多
	int left = 0;
	int right = s.size() - 1;
	while (left <= right) {
		if (s[left] != s[right]) {
			return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
		}
		left++;
		right--;

	}
	return true;


}


// 88. 合并两个有序数组 ——需要注意归并数组提前清空的问题
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// 第一版
	/*int last = (m--) + (n--) - 1;
	while (n >= 0) {
		nums1[last--] = m >= 0 && nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}*/

	// 0ms 版 —— 或计算比与计算一般来说要减少一定的耗时，m和n的自增自减也耗时
	int last = m + n - 1;
	while (n) {
		nums1[last--] = m == 0 || nums1[m - 1] <= nums2[n - 1] ? nums2[--n] : nums1[--m];
	}
}


// 524. 通过删除字母匹配到字典里最长单词
string findLongestWord(string s, vector<string>& d) {
	// me 问题：没有按照字典顺序排序
	/*int max = 0;
	int flag = 0;
	bool flag1;
	int s1 = 0, s2 = 0;
	for (int i = 0; i < d.size(); i++) {
		flag1 = false;
		s1 = s2 = 0;
		while (s2 < d[i].size()) {
			if (s1 > s.size()) { flag1 = false; break; }
			if (s[s1] == d[i][s2]) {
				s1++; s2++;
				flag1 = true;
			}
			else s1++;
		}
		if (flag1 && d[i].size() > max) {
			flag = i;
			max = d[i].size();
		}
	}
	return d[flag];*/




}




int main() {
	string a1[4] = { "ale", "apple", "monkey", "plea" };
	vector<string> a(a1, a1 + 4);
	string m = findLongestWord("abpcplea", a);

	return 0;
}