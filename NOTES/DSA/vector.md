# 向量

向量和列表都是线性序列。



## ADT（Abstract Data Type，抽象数据类型）

<img src=".\img\vector-模板.png" height=300px>

## 向量接口

### 向量的构造和析构



### 可扩充向量——动态空间管理

<img src=".\img\可扩充向量.png" height=300px>

#### 动态分配策略——加倍

```C++
T* oldElem = _elem; _elem = new T[_capacity<<=1];
```

原因：

<img src="\img\倍增策略对比.png" height="270px"> 通过空间的损失换取时间上的收益 

#### 平均分析 VS 分摊分析

### 元素访问

<img src="\img\元素访问.png" height="200px">

### 元素插入

![image-20200303220924718](C:\Users\yn\Desktop\C++\NOTES\DSA\img\元素插入.png)

### 区间删除

![image-20200303221236290](C:\Users\yn\Desktop\C++\NOTES\DSA\img\区间删除.png)

### 单元素删除

视作为区间删除操作的特例：`[r] = [r, r+1)`

单元数删除反复调用来实现区间删除成本大于整体区间删除，因为多次重复的平移，可能导致$o(n)$ 的复杂度。

### 遍历

![image-20200303223917431](C:\Users\yn\Desktop\C++\NOTES\DSA\img\元素遍历.png)

### 唯一化算法

#### 无序向量

截图



#### 有序向量

- 有序性甄别任意一组相邻元素是逆序的就是无序向量。

- 有序向量的优点能够高效的进行唯一化计算

- **低效的根源在于：同一个元素可作为被删除元素的后继进行多次前移**

  ![image-20200303225233493](C:\Users\yn\Desktop\C++\NOTES\DSA\img\向量唯一化.png)

### 查找算法

#### 无序向量

![image-20200303221601999](C:\Users\yn\Desktop\C++\NOTES\DSA\img\元素查找.png)

#### 有序向量

**语义约定**

```C++
//便于自身维护 保持整体有序性
V.insert(1 + V.search(e), e)
// 约定：在有序向量区间V[lo, hi)中却额定不大于e的最后一个元素的秩
// 若 -∞ < e < V[lo], 则返回lo-1（左侧哨兵）
// 若 V[hi-1] < e < +∞, 则返回hi-1（末元素 = 右侧哨兵左邻）    
```

##### 二分查找

