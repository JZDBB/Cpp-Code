# Basis

所谓算法，即特定计算模型下，旨在解决特定问题的指令序列

- 输入：待处理的信息 (问题)
- 输出：经处理的信息 (答案)
- 正确性：可以解决指定的问题
- 确定性：任一算法都可以描述为由基本操作组成的序列可行性每一基本操作都可实现 ,且在常数时间内完成
- 有穷性：对于任何输入 ,经有穷次基本操作，都可以得到输出 

**好算法**：正确、健壮、可读，最主要是**计算效率和存储空间**
`Algorithm + Data Structure = Programs`
`(Algorithm + Data Structure) x Efficiency = Computation`



## 度量方法

成本：运行时间 + 所需存储空间（运行时间可以转换为基本操作执行次数）

计算成本——最大成本 $T(n)=max{T(p)|p={n}}$

### $\mathcal{O} $ 记号

#### 渐进分析

$n \ge 2$ 所需的基本操作次数$T(n)$，和所需占用存储单元$S(n)$。

$\mathcal{O}$ **记号**

$T(n)=\mathcal{O}(f(n))$ 存在$c >0, \ n \gg 2$ 时，有$T(n)<cf(n)$

$\sqrt{5n[n(n+2)+4]+6}<\sqrt{5n[6n^2+4]+6}<\sqrt{35n^2+6}<6n^{1.5}=\mathcal{O}(n^{1.5})$

$f(n)$ 更简洁，反应增长趋势

- 常系数可忽略：$\mathcal{O}(cf(n))=\mathcal{O}(f(n))$
- 低次项可忽略：$\mathcal{O}(n^a+n^b)=\mathcal{O}(n^a),\ a>b>0$

<img src="\img\大O记号渐进分析.png" height=180px>

- $\mathcal{O}(1)$ 
  - 极其高效几乎不占多少开销
  - 常数计算时间——如加减乘除 $2 = 2013 = 2013\times 2013 = 2013 =2013^{2013}=\mathcal{O}(1)$ 
  - 不包含循环
  - 不含分支转向`if((n+m)*(n+m)<2*n*m) goto UNREACHABLE`
  - 不能有递归调用

- $\mathcal{O}(logn)$ 
  - 底数无所谓，同时幂次可以忽略：$logn^c=clogn=\Theta(logn)$
  - 非常高效，复杂度在无限接近于常数。
- $\mathcal{O}(n^c)$ 
  - 多项式简化：$a_kn^k+a_{k-1}n^{k-1}+a_{k-2}n^{k-2}+...+a_{1}n+a_0=\mathcal{O}(n^k)$
  - 幂次也可以简化估算
  - 效率相对令人满意
- $\mathcal{O}(2^n)$ 
  - 指数复杂度：$ \forall c>1, n^c=\mathcal{O}(2^n)$
  - 不可忍受！！
  - 从$\mathcal{O}(n^c)$ 到$\mathcal{O}(2^n)$ 是有效算法和无效算法的分水岭。

#### 其他记号

<img src="\img\其他记号.png" height=250px>

**例子：**

- 枚举法：$S$ 包含$n$个正整数，$\sum S=2m$，问是否存在子集$T$，使得$\sum T=m$。将所有子集进行枚举，计算复杂度为$2^n$ ——不理想



## 算法分析

两个任务 = 正确性（不变性 x 单调性）+ 复杂度

**复杂度层次级别表：**

<img src="\img\复杂度层次级别.png" height=350px>

#### 复杂度

分析的主要方法：迭代，递归，猜测+验证

**级数**

- 算数级数：$T(n)=1+2+...+n=n(n+1)/2=\mathcal{O}(n^2)$
- 幂次方级数：$T(n)=1^2+2^2+...+n^2=n(n+1)(2n+1)/6=\mathcal{O}(n^3)$ 证明：$\sum^n_{k=0}k^d=\mathcal{O}(n^{d+1})$
- 几何级数：$T_a(n)=a^0+a^1+...+a^n=(a^{n+1}-1)/(a-1)=\mathcal{O}(a^n)$ 
- 收敛级数：每一项都是小于前一项，是收敛的，复杂度为$\mathcal{O}(1)$
- 未必收敛，但是长度有限：
  - 调和级数：$h(n)=1+1/2+...+1/n=\Theta(logn)$
  - 对数级数：$h(n)=log1+log2+...+logn=log(n!)=\Theta(nlogn)$

**循环的复杂度计算**——找出规律：

<img src="\img\循环复杂度.png" height=350px>

#### 算法正确性

- 不变性：经$k$轮扫描交换后，最大的$k$个元素必然就位心
- 单调性：经$k$轮扫描交换后,问题规模缩减至$n-k$
- 正确性：经至多$n$趟扫描后,算法必然终止，且能给出正确解答 



### 封底估算

<img src="\img\封底估算.png" height=300px>

## 递归策略

### 减而治之

<img src="\img\减而治之-概念.png" height=300px>

求一串数的和：

<img src="\img\递归求和.png" height=220px>

**例子数组倒置**

```C++
void reverse(int* A, int lo, int hi){
    if(lo<hi){
        swap(A[lo], A[hi]); reverse(A, lo+1, hi+1);
    }// 递归算法
    while(lo<hi) swap(A[lo++], A[hi--]); // 迭代算法
}
```

### 分而治之

<img src="\img\分而治之-概念.png" height=300px>

二分求和

<img src="\img\分而治之-示例.png" height=300px>

## 迭代策略

递归算法一般都能够转化为迭代算法。

找数组区间最大的两个整数：

```C++
// 方法一 迭代
找到区间的最大值，记录index。从lo到index-1找最大数，从index+1到hi找最大数，对比两个数的大小得到次大数，开销为2n-3
// 方法二 迭代
通过x1，x2指针进行从lo到hi的扫描，先将所有数进行和A[x2]对比，大于A[x2]则更新x2的，再比较如果大于A[x1]，则x2和x1交换。开销为最小n-1，最大为2n-3
// 方法三 递归+分治法
取中间坐标，求前一半和后一半的各自最大最小数进行对比，得到。T(n)=2T(n/2)+2=5n/3-2
```



## 动态规划

### Fib()递归

<img src="\img\FIB递归.png" height=300px>

$\Phi^{36} \approx 2^{25}, \quad \Phi^{43} \approx 2^{30} \approx 10^9flo \approx 1 sec, \quad \Phi^5\approx 10, \quad \Phi^{92}\approx 10^{19}flo \approx 10^{10} sec\approx 3\  century$

因为在递归中有大量重复的递归实例，比如在$fib(n-1)$ 和$fib(n-2)$中就包含了很多$fib(2)$ 的计算，事实上只需要一次计算。这就是递归效率低的原因。

#### 解决方案

- 记忆方法：将已经计算的结果进行**制表备查**

  ```C++
  __int64 fib(int n, __int64& prev) { //计算Fibonacci数列第n项（线性递归版）：入口形式fib(n, prev)
  	if (0 == n){ //若到达递归基
  		prev = 1; return 0;
  	} //直接取值：fib(-1) = 1, fib(0) = 0
  	else { //否则
  		__int64 prevPrev; prev = fib(n - 1, prevPrev); //递归计算前两项
  		return prevPrev + prev; //其和即为正解
  	}
  } //用辅助变量记录前一项，返回数列的当前项，O(n)
  ```

- **动态规划**：颠到计算方向：由自顶向下的递归，改为自底而上的迭代方法

  ```C++
  __int64 fibI(int n) {
  	__int64 f = 1, g = 0; //初始化：fib(-1)、fib(0)
  	while (0 < n--) { g += f; f = g - f; } //依据原始定义，通过n次加法和减法计算fib(n)
  	return g; //返回
  }
  ```

  

### LCS 最长公共子序列

<img src="\img\LCS.png" height=300px>

#### 递归方法

```C++
// 对于序列A[0,n)和B[0,m)，LCS( n，m )三种情况
(0)若n=-1或m=-1,则取作空序列("")  //递归基
(1)若A[n]='X'=B[m]，则取作:LCS(n-1，m-1)+'X'  //减而治之
(2) A[n]≠B[m]，则在 LCS(n,m-1)与LCS(n-1,m)的结果中取更长者  //分而治之
```

##### 复杂度

- 如果不出现第二种分而治之的情况，最坏的时间为$o(n+m)$
- 最糟糕的是每次都分而治之，最终的$C_n^{n+m}$的开销，当$n=m$时，为$o(2^n)$

#### 迭代算法

将所有子问题列为一个表，颠到次序从`LCS(A[0], B[0])` 出发依次得到所有项。计算复杂度$o(n\times m)$

<img src="\img\LCS迭代.png" height=300px>