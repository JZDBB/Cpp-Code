#include"vector_func.h"

// 1095
int binarysearch(int target, MountainArray &mountainArr, int lo, int hi, bool key) {
	if (key) {
		while (hi >= lo) {
			int mid = lo + (hi - lo) / 2;
			int mi = mountainArr.get(mid);
			if (mi == target) return mid;
			else if (mi < target) lo = mid + 1;
			else hi = mid - 1;
		}
	}
	else {
		while (hi >= lo) {
			int mid = lo + (hi - lo) / 2;
			int mi = mountainArr.get(mid);
			if (mi == target) return mid;
			if (mi > target) lo = mid + 1;
			else hi = mid - 1;
		}
	}
	return -1;
}
int findInMountainArray(int target, MountainArray &mountainArr) {
	int len = mountainArr.length();
	int peek;
	int l = 0;
	int r = len - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		int left = mid > 0 ? mountainArr.get(mid - 1) : mountainArr.get(mid) - 1;
		int right = mid<len-1? mountainArr.get(mid + 1): mountainArr.get(mid) - 1;
		int mi = mountainArr.get(mid);
		if (mi > left && mi > right) {
			peek = mid;
			break;
		}
		else if (mi < left) r = mid - 1;
		else l = mid + 1;
	}
	int flag = binarysearch(target, mountainArr, 0, peek, true);
	if (flag != -1) return flag;
	else return binarysearch(target, mountainArr, peek, len - 1, false);
}