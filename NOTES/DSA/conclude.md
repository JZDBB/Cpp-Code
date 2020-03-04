## 常见算法开销
折半的算法：（二分查找）：$T(n)=T(n/2)+\mathcal{O}(1)=\mathcal{O}(logn)$ 

归并排序：$T(n)=2T(n/2)+o(n)=o(nlogn)$。





## 排序算法归纳

### 向量排序

- 冒泡排序
- 归并排序

### 列表排序

#### 选择排序（效率较高的冒泡排序）

![image-20200304175433258](C:\Users\yn\Desktop\C++\NOTES\DSA\img\选择排序.png)

![image-20200304175836553](C:\Users\yn\Desktop\C++\NOTES\DSA\img\列表找最大值.png)

##### 开销：

- `sellectMax()` 开销为$o(n-k)$
- `remove()` 和 `insertBefor()` 开销均为$o(1)$
- 总开销：$\Theta(n^2)$，无论最好最坏开销相同。
- 优势在于，减少了在实际中的**移动操作**。主要开销来自于比较操作。这是比向量较好的。

#### 插入排序



