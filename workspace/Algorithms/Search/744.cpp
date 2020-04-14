#include"Search.h"

// 744. 寻找比目标字母大的最小字母
char nextGreatestLetter(vector<char>& letters, char target) {
	int left = 0;
	int right = letters.size();
	while (left < right) {
		int mi = left + (right - left) / 2;
		letters[mi] > target ? right = mi : left = mi + 1;
	}
	if (right == letters.size()) return letters[0];
	
	return letters[left];
}