#include"vector_func.h"

// 912. ÅÅĞòÊı×é

//Ñ¡ÔñÅÅĞò
void SelectSort(vector<int>& nums, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) min = j;
		}
		if (min != i) swap(nums[min], nums[i]);
	}
}


// Ã°ÅİÅÅĞò
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

// ²åÈëÅÅĞò
void InsertSort(vector<int>& nums, int n) {
	for (int i = 1; i < n; i++){
		int j = i - 1;
		int k = nums[i];
		while (j > -1 && k < nums[j]){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = k;
	}
}

// Ï£¶ûÅÅĞò ¡ª¡ª ¸Ä½ø°æ²åÈëÅÅĞò
void ShellSort(vector<int>& nums, int n) {
	for (int h = n / 2; h >= 1; h = h / 2) {
		for (int i = h; i < n; i++) {
			int j = i - h;
			int k = nums[i];
			while (j > -1 && k < nums[j]) {
				nums[j + h] = nums[j];
				j -= h;
			}
			nums[j + h] = k;
		}
	}
}


// ¹é²¢
void Merge(vector<int>& nums, int start1, int end1, int start2, int end2) {
	for (int i = start2; i <= end2; i++) {
		int j = i - 1;
		int k = nums[i];
		while (j >= start1 && nums[j] > k) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = k;
	}
}
void MergeSort(vector<int>& nums, int start, int end) {
	if (end - start < 1) return;
	int mi = start + (end - start) / 2;
	MergeSort(nums, start, mi);
	MergeSort(nums, mi + 1, end);
	Merge(nums, start, mi, mi + 1, end);
}

void MergeSort(vector<int>& nums, int n) {
	MergeSort(nums, 0, n - 1);
}

// ¿ìËÙÅÅĞò
int partition(vector<int>& nums, int low, int high) {
	int a = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= a) high--;
		nums[low] = nums[high];
		while (low < high && nums[low] <= a) low++;
		nums[high] = nums[low];
	}
	nums[low] = a;
	return low;
}
void QuickSort(vector<int>& nums, int low, int high) {
	if (high - low < 1)return;
	int mi = partition(nums, low, high);
	QuickSort(nums, low, mi - 1);
	QuickSort(nums, mi + 1, high);
}

// ¶ÑÅÅĞò
void build_heap(vector<int> &nums, int size, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	int max = index;
	if (left < size && nums[left]>nums[max]) max = left;
	if (right < size && nums[right]>nums[max]) max = right;

	if (max != index) {
		swap(nums[index], nums[max]);
		build_heap(nums, size, max);
	}
}
void HeapSort(vector<int> &nums, int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		build_heap(nums, size, i);
	}
	for (int i = size - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		build_heap(nums, i, 0);
	}
}


// ¼ÆÊıÅÅĞò
void CountSort(vector<int>& nums) {
	int min = nums[0];
	int max = nums[0];
	unordered_map<int, int> m;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < min) min = nums[i];
		if (nums[i] > max) max = nums[i];
	}
	for (int i = min; i <= max; i++) {
		if (find(nums.begin(), nums.end(), i) != nums.end()) m[i]++;
	}
	int index = 0;
	for (int i = min; i <= max; i++) {
		if (m.find(i) != m.end()) {
			for (int j = 0; j < m[i]; j++) nums[index++] = i;
		}
	}
}

// Í°ÅÅĞò
void bucketSort(vector<int>& nums){
	
}

// »ùÊıÅÅĞò
void RadixSort(vector<int>& nums) {
	int max = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (max < nums[i]) max = nums[i];
	}
	int bit = 0;
	while (max) {
		max /= 10;
		bit++;
	}
	for (int i = 1; i <= bit; i++) {
		vector<vector<int>> vessel(10, vector<int>(0, 0));
		for (int j = 0; j < nums.size(); j++) {
			int diff = nums[j] / pow(10, i - 1);
			diff = diff % 10;
			vessel[diff].push_back(nums[j]);
		}
		int index = 0;
		for (int k = 0; k < vessel.size(); k++) {
			for (auto item : vessel[k]) {
				nums[index++] = item;
			}
		}
	}
}


vector<int> sortArray(vector<int>& nums) {
	int n = nums.size();
	HeapSort(nums, n);
	return nums;
}
