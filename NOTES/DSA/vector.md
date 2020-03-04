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

- **A 方案 减而治之**

![image-20200304140640921](C:\Users\yn\Desktop\C++\NOTES\DSA\img\二分查找-减而治之.png)

**复杂度：**线性递归：$T(n)=T(n/2)+\mathcal{O}(1)=\mathcal{O}(logn)$ 

![image-20200304142121353](C:\Users\yn\Desktop\C++\NOTES\DSA\img\递归二分查找复杂度.png)

- **改进A方案**

  左右比较次数不等，递归深度却相同，可以通过递归深度不均衡来对转向成本不均衡进行补偿。

![image-20200304143008926](C:\Users\yn\Desktop\C++\NOTES\DSA\img\Fid二分查找复杂度.png)

**通用策略**

![image-20200304143134327](C:\Users\yn\Desktop\C++\NOTES\DSA\img\通用策略.png)

证明：在$[0, 1)$ 内取$\lambda$何值为最优，设平均查找长度为$\alpha(\lambda)log_2n$

​			递推式：$\alpha(\lambda)log_2n=\lambda[1+\alpha(\lambda)log_2(\lambda n)]+(1-\lambda)[2+\alpha(\lambda)log_2((1-\lambda) n)]$

​			整理：$\frac{-ln2}{\alpha(\lambda)}=\frac{\lambda ln\lambda+(1-\lambda)ln(1-\lambda)}{2-\lambda}$ 求导后得到$\lambda=\phi$ 时，$\alpha(\lambda) \approx 1.44$最小。

- **B方案**

改进转向不平衡——只有两个方向，`e<x`和`e>=x` 两个方向

![image-20200304144810684](C:\Users\yn\Desktop\C++\NOTES\DSA\img\B方案二分查找.png)

- **C方案二分查找**

语义约定：多个命中返回秩最大者，失败返回小于e的最大者。

![image-20200304150305620](C:\Users\yn\Desktop\C++\NOTES\DSA\img\最终方案-二分查找.png)



#### 插值查找（扩）





### 排序算法

- **冒泡排序**

  - 问题:给定n个可比较的元素，将它们按(非降)序排列

  - **观察:**有序/无序序列中,任何/总有一对相邻元素顺序/逆序

  - **扫描交换**:依次比较每一对相邻元素;如有必要,交换之

  - 若整趟扫描都没有进行交换,则排序完成;否则,再做一趟扫描交换 

  - 提前终止版

    ![image-20200304151733891](C:\Users\yn\Desktop\C++\NOTES\DSA\img\冒泡排序-code.png)

  - 跳跃版

    ![image-20200304153046676](C:\Users\yn\Desktop\C++\NOTES\DSA\img\冒泡排序-code2.png)

  - **综合评价：**

    - 最好情况为$0(n)$， 最差为$o(n^2)$

    - 稳定的：因为在重复数组输入输出的相对次序是保持不变的——有赖于 `if` 判断后的交换语句中为 `>` 而不是 `>=`

      ![image-20200304153701154](C:\Users\yn\Desktop\C++\NOTES\DSA\img\排序算法-稳定性.png)

  

- **归并排序**

  - 分治策略：划分子序列 $o(1)$，子序列递归排序 $2 \times T(n/2)$，子序列合并$o(n)$

  - 最终复杂度$T(n)=2T(n/2)+o(n)=o(nlogn)$。

  - 子序列合并中消耗为两个子序列长度成线性关系。

    ![image-20200304155947874](C:\Users\yn\Desktop\C++\NOTES\DSA\img\归并排序-子序列合并.png)

  - 优点：算法性能好，具有稳定性，可扩展性好，易于并行。
  - 缺点：需要对等规模的存储空间，在输入接近有序的时候开销依然是$o(nlogn)$