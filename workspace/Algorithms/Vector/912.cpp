#include"vector_func.h"

// 912. 排序数组

//选择排序
void SelectSort(vector<int>& nums, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) min = j;
		}
		if (min != i) swap(nums[min], nums[i]);
	}
}

// 插入排序
void InsertSort(vector<int>& nums, int n) {
	for (int i = 1; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (nums[i] < nums[j]) flag = true;
			if (flag) swap(nums[i], nums[j]);
		}
	}
}

// 冒泡排序
void BubbleSort(vector<int>& nums, int n) {
	for (int i = 0; i < n - 1; i--) {
		bool flag = false;
		for (int j = n - 1; j > i; j--) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				flag = true;
			}
		}
		if (flag) return;
	}
}



vector<int> sortArray(vector<int>& nums) {
	int n = nums.size();
	InsertSort(nums, n);
	return nums;
}




////希尔
//void ShellSort(vector<int>& nums, int n) {
//	for (int dk = n / 2; dk >= 1; dk = dk / 2) {
//		for (int i = dk; i < n; ++i) {
//			if (nums[i] < nums[i - dk]) {
//				int tmp = nums[i], j;
//				for (j = i - dk; j >= 0 && tmp < nums[j]; j -= dk) {
//					nums[j + dk] = nums[j];
//				}
//				nums[j + dk] = tmp;
//			}
//		}
//	}
//}
////快排
//void QuickSort(vector<int>& nums, int low, int high, int n) {
//
//	if (low < high) {
//		int pivotpos = partition(nums, low, high);
//		QuickSort(nums, low, pivotpos - 1, n);
//		QuickSort(nums, pivotpos + 1, high, n);
//	}
//}
//int partition(vector<int>& nums, int low, int high) {
//	int pivot = nums[low];
//	while (low < high) {
//		while (low < high && nums[high] >= pivot)--high;
//		nums[low] = nums[high];
//		while (low < high && nums[low] <= pivot) ++low;
//		nums[high] = nums[low];
//	}
//	nums[low] = pivot;
//	return low;
//
//}
//
////堆排序
//void adjust(vector<int> &nums, int len, int index) {
//	int left = 2 * index + 1; // index的左子节点
//	int right = 2 * index + 2;// index的右子节点
//
//	int maxIdx = index;
//	if (left<len && nums[left] > nums[maxIdx])     maxIdx = left;
//	if (right<len && nums[right] > nums[maxIdx])     maxIdx = right;
//
//	if (maxIdx != index)
//	{
//		swap(nums[maxIdx], nums[index]);
//		adjust(nums, len, maxIdx);
//	}
//
//}
//
//// 堆排序
//void HeapSort(vector<int> &nums, int size) {
//	for (int i = size / 2 - 1; i >= 0; i--) {
//		adjust(nums, size, i);
//	}
//	for (int i = size - 1; i >= 1; i--) {
//		swap(nums[0], nums[i]);
//		adjust(nums, i, 0);
//	}
//}