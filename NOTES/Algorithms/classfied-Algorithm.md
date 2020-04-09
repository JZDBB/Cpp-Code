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

#### 复杂度和性质

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
	for (int i = 1; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (nums[i] < nums[j]) flag = true;
			if (flag) swap(nums[i], nums[j]);
		}
	}
}
```

