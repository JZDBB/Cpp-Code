# 向量

向量和列表都是线性序列。

<img src=".\img\ADT vs DS.png" width="600px">

## 向量

<img src=".\img\vector-模板.png" height=300px>

## 向量接口

### 向量的构造和析构



### 可扩充向量——动态空间管理

<img src=".\img\可扩充向量.png" width=600px>

#### 动态分配策略——加倍

```C++
T* oldElem = _elem; _elem = new T[_capacity<<=1];
```

原因：

<img src=".\img\倍增策略对比.png" height="270px"> 通过空间的损失换取时间上的收益 

#### 平均分析 VS 分摊分析

### 元素访问

<img src=".\img\元素访问.png" width="600px">

### 元素插入
<img src=".\img\元素插入.png" width="600px">


### 区间删除
<img src=".\img\区间删除.png" width="600px">


### 单元素删除

视作为区间删除操作的特例：`[r] = [r, r+1)`

单元数删除反复调用来实现区间删除成本大于整体区间删除，因为多次重复的平移，可能导致$o(n)$ 的复杂度。

### 遍历
<img src=".\img\元素遍历.png" width="600px">

### 唯一化算法

#### 无序向量

<img src=".\img\无序向量去重.png" width=600px>

#### 有序向量

- 有序性甄别任意一组相邻元素是逆序的就是无序向量。

- 有序向量的优点能够高效的进行唯一化计算

- **低效的根源在于：同一个元素可作为被删除元素的后继进行多次前移**
<img src=".\img\向量唯一化.png" width="600px">

### 查找算法

#### 无序向量
<img src=".\img\元素查找.png" width="600px">

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

- **A 方案 减而治之**
<img src=".\img\二分查找-减而治之.png" width="600px">

**复杂度：**线性递归：$T(n)=T(n/2)+\mathcal{O}(1)=\mathcal{O}(logn)$ 

<img src=".\img\递归二分查找复杂度.png" width="600px">

- **改进A方案**

  左右比较次数不等，递归深度却相同，可以通过递归深度不均衡来对转向成本不均衡进行补偿。

  <img src=".\img\Fid二分查找复杂度.png" width="600px">

**通用策略**

<img src=".\img\通用策略.png" width="600px">

证明：在$[0, 1)$ 内取$\lambda$何值为最优，设平均查找长度为$\alpha(\lambda)log_2n$

​			递推式：$\alpha(\lambda)log_2n=\lambda[1+\alpha(\lambda)log_2(\lambda n)]+(1-\lambda)[2+\alpha(\lambda)log_2((1-\lambda) n)]$

​			整理：$\frac{-ln2}{\alpha(\lambda)}=\frac{\lambda ln\lambda+(1-\lambda)ln(1-\lambda)}{2-\lambda}$ 求导后得到$\lambda=\phi$ 时，$\alpha(\lambda) \approx 1.44$最小。

- **B方案**

改进转向不平衡——只有两个方向，`e<x`和`e>=x` 两个方向

<img src=".\img\B方案二分查找.png" width="600px">

- **C方案二分查找**

语义约定：多个命中返回秩最大者，失败返回小于e的最大者。

<img src=".\img\最终方案-二分查找.png" width="600px">

