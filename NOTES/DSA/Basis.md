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



## 动态规划

