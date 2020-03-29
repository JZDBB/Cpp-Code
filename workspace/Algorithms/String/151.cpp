#include"string_func.h"

// 151. 翻转字符串里的单词 ——**
string reverseWords(string s) {
	// 多次赋值很耗时
	/*string res;
	int i = 0;
	while (i<s.size()) {
		string word;
		int len = 0;
		while (s[i] != ' '&& i<s.size()) {
			word.insert(word.end(), s[i++]);
			len++;
		}
		if (!word.empty()) {
			res.insert(res.begin(), ' ');
			for (int k = len - 1; k >= 0; k--) {
				res.insert(res.begin(), word[k]);
			}
		}
		i++;
	}
	res.pop_back();
	return res;*/

	if (s.empty()) return "";
	//先反转
	reverse(s.begin(), s.end());
	//去除前后空格
	int start = 0, end = s.size() - 1;
	while (s[start] == ' ' && start < s.size()) start++;
	while (s[end] == ' ' && end > 0) end--;
	if (start > end) return "";

	//对单词进行反转(两个指针-快慢指针，确定需要反转的单词)
	for (int right = start, left = start; right <= end;)
	{
		while (s[right] != ' ' && right <= end) right++;
		reverse(s.begin() + left, s.begin() + right);
		left = right;
		while (s[left] == ' ' && left <= end) left++;
		right = left;
	}

	//去掉单词间的多余空格
	int new_index = start;
	for (int i = start; i <= end; i++)
	{
		if (s[i] == ' ' && s[i - 1] == ' ') continue;
		s[new_index] = s[i];
		new_index++;
	}
	return s.substr(start, new_index - start);
}