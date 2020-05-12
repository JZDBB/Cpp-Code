# 动态规划

### 套路

- **动态规划问题的一般形式就是求最值，求解动态规划的核心问题是穷举，存在「重叠子问题」**
- 动态规划问题一定会**具备「最优子结构」**，才能通过子问题的最值得到原问题的最值。列出**正确的「状态转移方程」**才能正确地穷举。
- **重叠子问题**、**最优子结构**、**状态转移方程**就是动态规划三要素。

*明确「状态」 —> 定义 dp 数组/函数的含义 —> 明确「选择」—> 明确 base case。*

```C++
// 套路
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 计算(选择1，选择2...)
```

## Demo

#### 斐波那契数列

```C++
int fib(int N) {
    if (N == 1 || N == 2) return 1;
    return fib(N - 1) + fib(N - 2);
}

// 动态规划
int fib(int N) {
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}
```



## 最优子结构

当一个问题的最优解包含其子问题的最优解时，称此问题具有最优子结构性质。

运用贪心策略在每一次转化时都取得了最优解。

问题的最优子结构性质是该问题可用贪心算法或动态规划算法求解的关键特征。

贪心算法的每一次操作都对结果产生直接影响，而动态规划则不是。

**贪心算法对每个子问题的解决方案都做出选择，不能回退；动态规划则会根据以前的选择结果对当前进行选择，有回退功能。**

动态规划主要运用于二维或三维问题，而贪心一般是一维问题。

**要符合「最优子结构」，子问题间必须互相独立**。



## 动态规划问题

### 设计思路——数学归纳

[300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

- 首先要定义清楚 dp 数组的含义？**dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。**
- 思考如何进行状态转移：**找到前一个比nums[i]小的数的最长的递增子序列长度+1即可**。采用数学归纳法，假设 `dp[0...i-1]` 都已知，想办法求出 `dp[i]`
- 但如果无法完成这一步，很可能就是 `dp` 数组的定义不够恰当，需要重新定义 `dp` 数组的含义；或者可能是 `dp` 数组存储的信息还不够，不足以推出下一步的答案，需要把 `dp` 数组扩大成二维数组甚至三维数组。

```C++
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size());  int res = 0;  dp[0] = 1; // 初始化
	for (int i = 1; i < dp.size(); i++) {
		int index = i - 1;
		while (index >= 0) {
			if (nums[index] < nums[i]) dp[i] = max(dp[index] + 1, dp[i]);
			index--;
		}
		dp[i] = max(1, dp[i]);
		res = res < dp[i] ? dp[i] : res;
	}
	return res;
}
```

###  背包问题

#### 0-1背包问题

**明确两点，「状态」和「选择」**

- 状态有两个，就是「背包的容量」和「可选择的物品」
- 选择就是「装进背包」或者「不装进背包」

**明确** **`dp`** **数组的定义**。

`dp[i][w]` 的定义如下：对于前 `i` 个物品，当前背包的容量为 `w`，这种情况下可以装的最大价值是 `dp[i][w]`。

**根据「选择」，思考状态转移的逻辑**。

- 没有把这第`i`个物品装入背包，最大价值 `dp[i][w]` 应该等于 `dp[i-1][w]`，继承之前的结果。
- 如果把这第 `i` 个物品装入了背包，那么 `dp[i][w]` 应该等于 `dp[i-1][w - wt[i-1]] + val[i-1]`。

##### code

```C++
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (w - wt[i-1] < 0) dp[i][w] = dp[i - 1][w]; // 这种情况下只能选择不装入背包
            else dp[i][w] = max(dp[i - 1][w - wt[i-1]] + val[i-1], dp[i - 1][w]);
            // 装入或者不装入背包，择优
            }
        }
    }
    return dp[N][W];
}
```

#### 完全背包问题

[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)

转换为：有一个背包，最大容量为 `amount`，有一系列物品 `coins`，每个物品的重量为 `coins[i]`，**每个物品的数量无限**。

状态为背包容量+可选物品，选择为是否装进背包。

`dp[i][j]` 的定义：若只使用前 `i` 个物品，当背包容量为 `j` 时，有 `dp[i][j]` 种方法可以装满背包。

```C++
int change(int amount, vector<int>& coins) {
    int n = coins.size(); vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
	for (int i = 0; i <= n; i++) dp[i][0] = 1; // 边界问题
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= amount; j++) {
			if (j - coins[i - 1] >= 0) 
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; // 两种之和
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[coins.size()][amount];
}
```

#### 子集背包问题

[416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)

转换为：给一个可装载重量为 `sum / 2` 的背包和 `N` 个物品，每个物品的重量为 `nums[i]`

```C++
bool canPartition(vector<int>& nums) {
	int sum = 0; for (int i : nums) sum += i;
	if (sum % 2 != 0) return false;
	int all = sum / 2; int n = nums.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(all + 1, false));
	for (int i = 0; i <= n; i++) dp[i][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= all; j++) {
			if (j - nums[i - 1] < 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
		}
	}
	return dp[n][all];
}
```

**PS: 状态压缩**：**注意到** **`dp[i][j]`** **都是通过上一行** **`dp[i-1][..]`** **转移过来的**

状态压缩可以只在一行 `dp` 数组上操作，`i` 每进行一轮迭代，`dp[j]` 就相当于 `dp[i-1][j]`。

**唯一需要注意的是** **`j`** **应该从后往前反向遍历，因为每个数字只能用一次，以免之前的结果影响其他的结果**。因此此处压缩后采用逆序就是保证在`i`循环时，`dp[j]`中保存的`dp[i-1][j]` 的值不会因为前面`dp[i-1][j-1]` 的值改变而改变。

```C++
bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();   for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;  sum = sum / 2;  
    vector<bool> dp(sum + 1, false);   dp[0] = true;
    for (int i = 0; i < n; i++) 
        for (int j = sum; j >= 0; j--) 
            if (j - nums[i] >= 0) 
                dp[j] = dp[j] || dp[j - nums[i]];
    return dp[sum];
}
```



### 子序列问题

#### 最长公共子序列

[1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) 子序列类型的问题，穷举出所有结果不容易，而动态规划算法做的就是穷举 + 剪枝，所以只要涉及子序列问题，十有八九都需要动态规划来解决。

#### 编辑距离

[72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)

<img src="img\72.jpg" height=250px>

```C++
int minDistance(string word1, string word2) {
	int len1 = word1.size();  int len2 = word2.size();
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i <= len1; i++) dp[i][0] = i;
	for (int j = 0; j <= len2; j++) dp[0][j] = j;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];//注意word的取值范围
			else dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
		}
	}
	return dp[len1][len2];
}
```

#### 回文序列

[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/) 涉及遍历顺序的改变典型

**状态：在子串** **`s[i..j]`** **中，最长回文子序列的长度为** **`dp[i][j]`**

<img src="img/516_1.jpg" height="250px">

```C++
int longestPalindromeSubseq(string s) {
	int len = s.length();   if (len < 2) return len;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	for (int i = 0; i < len; i++) dp[i][i] = 1;
	for (int i = len-1; i >=0; i--) {
		for (int j = i + 1; j < len; j++) {
			if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
			else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][len-1];
}
```



### 高楼鸡蛋

- **状态：当前拥有的鸡蛋数** **`K`** **和需要测试的楼层数** **`N`**。随着测试的进行，鸡蛋个数可能减少，楼层的搜索范围会减小，这就是状态的变化。
- **选择：选择哪层楼扔鸡蛋。**
- **状态转移**
  - **如果鸡蛋碎了**，鸡蛋的个数 `K` 减一，搜索的楼层区间从 `[1..N]` 变为 `[1..i-1]` 共 `i-1` 层楼；
  - **如果鸡蛋没碎**，鸡蛋的个数 `K` 不变，搜索的楼层区间从 `[1..N]` 变为 `[i+1..N]` 共 `N-i` 层楼。

```C++
int superEggDropBS(int K, int N) {
	if (K == 1) return N;  if (N == 1) return 1;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) dp[i][1] = i;
	for (int k = 1; k <= K; k++) dp[1][k] = 1;
	for (int i = 2; i <= N; i++) {
		for (int k = 2; k <= K; k++) {
			int res = INT_MAX;int start = 1, end = i, mid; // 这一段改用二分查找做枚举
			while (start <= end) {
				mid = start + (end - start) / 2;
				if (dp[mid - 1][k - 1] == dp[i - mid][k]) {
					res = min(res, dp[mid - 1][k - 1] + 1);
					break;
				}
				else if (dp[mid - 1][k - 1] > dp[i - mid][k]) {
					end = mid - 1;
					res = min(res, dp[mid - 1][k - 1] + 1);
				}
				else {
					start = mid + 1;
					res = min(res, dp[i - mid][k] + 1);
				}
			}
			dp[i][k] = res;
		}
	}
	return dp[N][K];
}
```

#### 换一种思路

- 状态： **`K`** **个鸡蛋，测试** **`m`** **次，最坏情况下最多能测试** **`N`** **层楼**。
- 选择：
  - **无论你在哪层楼扔鸡蛋，鸡蛋只可能摔碎或者没摔碎，碎了的话就测楼下，没碎的话就测楼上**。
  - **无论你上楼还是下楼，总的楼层数 = 楼上的楼层数 + 楼下的楼层数 + 1（当前这层楼）**。

- 转移方程：

  ```
  dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1
  ```

  **`dp[k][m - 1]`** **就是楼上的楼层数**，因为鸡蛋个数 `k` 不变，鸡蛋没碎，扔鸡蛋次数 `m` 减一；

  **`dp[k - 1][m - 1]`** **就是楼下的楼层数**，因为鸡蛋个数 `k` 减一，鸡蛋碎了，同时扔鸡蛋次数 `m` 减一。

  <img src="img/887_1.jpg" height="250px">

```C++
int superEggDrop(int K, int N) {
    vector<vector<int>> dp(K+1, vector<int>(N+1));
    int m = 0;
    while(dp[K][m]<N){
        m++;
        for (int k = 1; k <= K; k++)
            dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
    }
    return m;
}
```



### 股票买卖问题

```C++
/*for 状态1 in 状态1的所有取值：
      for 状态2 in 状态2的所有取值：
          for ...
              dp[状态1][状态2][...] = 择优(选择1，选择2...) */

// 状态有三：当前时间，至今最多股票交易次数，是否持有股票
// 状态转移：买入，卖出，不变三种
没有股票：dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
持有股票：dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]);

// base case
dp[-1][k][0] = dp[i][0][0] = 0
dp[-1][k][1] = dp[i][0][1] = -infinity//-prices[0]
```

[例题](../../workspace/Algorithms/DP/121.cpp)



