#include"Greedy.h"

// 605. 种花问题
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int size = flowerbed.size();
	for (int i = 0; i < size; i++) {
		if (flowerbed[i] == 1) {
			i++;
			continue;
		}
		if ((i + 1 < size && flowerbed[i + 1] == 0)|| i == size-1) {
			n--;
			i++;
		}
		else i += 2;
	}
	return n <= 0;
}