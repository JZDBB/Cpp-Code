# 算法思想

## 双指针

- 主要特点：双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。
- 一般用法：

```C++
int front = 0;
int tail = A.length()-1
while(front < tail) { ... }
```

- 优点：减少计算复杂度一般能够将时间复杂度降幂。

- 适用场景：

  - 左右指针问题（**数组**）：二分查找、两数和、三数和等
  - 快慢指针问题（**链表**）：链表判定环问题

  <img src="./img/快慢指针.png" height="200px">

  - in place 问题：一个指针遍历，一个指针找对应交换的元素。——快速排序、奇偶排序、移动0等
  - 有序序列去重问题：

- 应用题

  - [盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

  <img src="./img/question_11.jpg" height=200px>

  ```C++
  int min(int a, int b){return a<b?a:b;}
  int maxArea(vector<int>& height) {
      int left = 0; int right = height.size()-1; int max = 0;
      while(left<right){
          int Area = min(height[left], height[right])*(right-left);
          if(Area > max) max = Area;
          if(height[left]<height[right]) left++;
          else right--;
      }
      return max;
  }
  ```

  左右夹逼——复杂度： 时间复杂度O(n), 空间复杂度O(1).






## 排序

- **比较类排序**：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn)，因此也称为非线性时间比较类排序。
- **非比较类排序**：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。 

<img src="./img/Sort分类.png" height="450px">

### 复杂度和性质

<img src="./img/Sort 复杂度.png" height="450px">



### Code

#### Bubble Sort

<img src="./img/Bubble Sort.gif" width="500px">

```C++
void BubbleSort(vector<int>& nums, int n) {
	for (int i = 0; i < n - 1; i--) {
		bool flag = false;
		for (int j = n - 1; j > i; j--) {
			if (nums[j] < nums[j - 1]) {
				swap(nums[j], nums[j - 1]);
				flag = true;
			}
		}
		if (flag) return; // 提前结束
	}
}
```



#### Selection Sort

<img src="./img/Selection Sort.gif" width="500px">

```C++
void SelectSort(vector<int>& nums, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) min = j;
		}
		if (min != i) swap(nums[min], nums[i]);
	}
}
```



#### Insertion Sort

<img src="./img/Insertion Sort.gif" width="500px">

```C++
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
```



#### Shell Sort

<img src="./img/Shell Sort.gif" width="500px">

```C++
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
	}// 改进版插入排序
}
```



#### Merge Sort

<img src="./img/Merge Sort.gif" width="500px">

```C++
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
```



#### Quick Sort

<img src="./img/Quick Sort.gif" width="500px">

```C++
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
```



#### Heap Sort

<img src="./img/Heap Sort.gif" width="500px">

大顶堆&小顶堆——二叉堆（优先队列）

```C++
void build_heap(vector<int> &nums, int size, int index){
    int left = 2*index+1;
    int right = 2*index+2;
    int max = index;
    if(left<size && nums[left]>nums[max]) max = left;
    if(right<size && nums[right]>nums[max]) max = right;
    if(max!=index){
        swap(nums[max], nums[index]);
        build_heap(nums, size, max);
    }
}
void HeapSort(vector<int> &nums, int size){
    for(int i = size/2-1;i>=0;i--) build_heap(nums, size, i);
    for(int i = size-1;i>0;i--){
        swap(nums[i], nums[0]);
        build_heap(nums, i, 0);
    }
}
```





#### Counting Sort

计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数

<img src="./img/Counting Sort.gif" width="500px">



#### Bucket Sort

桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。

<img src="./img/Bucket Sort.gif" width="500px">



#### Radix Sort

<img src="./img/Radix Sort.gif" width="500px">



**基数排序 vs 计数排序 vs 桶排序**

- 基数排序：根据键值的每位数字来分配桶；
- 计数排序：每个桶只存储单一键值；
- 桶排序：每个桶存储一定范围的数值；



## 二分查找

#### 边界问题！！！



**时间复杂度**

二分查找也称为折半查找，每次都能将查找区间减半，这种折半特性的算法时间复杂度为 $O(logN)$





## 贪心思想

是寻找**最优解问题**的常用方法，这种方法模式一般将求解过程分成**若干个步骤**，但每个步骤都应用贪心原则，选取当前状态下**最好/最优的选择**（局部最有利的选择），并以此希望最后堆叠出的结果也是最好/最优的解。

步骤1：从某个初始解出发；
步骤2：采用迭代的过程，当可以向目标前进一步时，就根据局部最优策略，得到一部分解，缩小问题规模；
步骤3：将所有解综合起来。