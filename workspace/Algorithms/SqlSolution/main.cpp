#include"LRU1.h"

int main() {
	LRUCache cache = LRUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	int a = cache.get(1);
	cache.put(3, 3);
	a = cache.get(2);
	cache.put(4, 4);
	a = cache.get(1);
	a = cache.get(3);
	a = cache.get(4);
	return 0;
}