# 数据结构

数据结构的存储方式只有两种：**数组（顺序存储）**和**链表（链式存储）**

## 链表

特点：元素不连续，链式访问耗时；删除时间复杂度 O(1)。每个元素必须存储指针，消耗储存空间。

典型例题：[234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)



## 数组



## 栈和队列

- 双栈实现队列&& 双队列实现栈

- **单调栈**：应用不广泛，主要用来实现Next Greater Element这一种典型问题。

- **单调队列**：[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/

- **优先队列**：

  ```C++
  // 升序队列
  priority_queue <int, vector<int>, greater<int> > q;
  // 降序队列
  priority_queue <int, vector<int>, less<int> >q;
  ```

  

## 哈希表

[unordered_map](https://zh.cppreference.com/w/cpp/container/unordered_map)

一般用在需要单次遍历，时间消耗较小。哈希表是一种更通用的解决方案，可以适应任何字符范围。

- 优点：
  查找、插入、删除只需要接近常量的时间即0(1)的时间级。哈希表运算得非常快，如果不需要有序遍历数据，并且可以提前预测数据量的大小。那么哈希表在速度和易用性方面是无与伦比的。
- 缺点：
  它是基于数组的，数组创建后难于扩展，某些哈希表被基本填满时，性能下降得非常严重，所以程序员必须要清楚表中将要存储多少数据，或者准备好定期地把数据转移到更大的哈希表中，这是个费时的过程。

**PS：哈希表常用在需要求和或者需要快速索引的代码中。**

##### 哈希应用：

- 前缀和+哈希表：[1371. 每个元音包含偶数次的最长子字符串](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)、[560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)



## 树

###	 DFS vs BFS

**BFS/DFS ：** 两者目标都是遍历整个矩阵，不同点在于搜索顺序不同。DFS 是朝一个方向走到底，再回退，以此类推；BFS 则是按照“平推”的方式向前搜索。

#### 棋盘问题

### BST

二叉查找树（BST）：根节点大于等于左子树所有节点，小于等于右子树所有节点。

二叉查找树中序遍历有序。



#### 字典树

```C++
class WordDictionary {
public:
    struct node{
        bool isEnd;
        unordered_map<char, node*> child;
        node(){isEnd=false;}
    };
    /** Initialize your data structure here. */
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p=root;
        for(auto c:word){
            if(!p->child.count(c))p->child.insert({c,new node()});
            p=p->child[c];
        }
        p->isEnd=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto p=root;
        return help(p,word.begin(),word.end());
    }
    template<typename it>
    bool help(node* root,it l,it r){
        if(l==r)return root->isEnd;
        if(*l=='.')
            for(auto t:root->child)
                if(help(t.second,l+1,r))return true;
        if(root->child.count(*l))return help(root->child[*l],l+1,r);
        return false;  
    }
};
```





### 套路

- 递归调用：[110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)、[563. 二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/)、[543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)、[129. 求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)、



## 字符串

相当于char所在的vector，主要是反转、回文，同构等应用。



## 图

邻接表表示：`graph[i]`表示图中与节点`i`相连的所有节点。每个节点都是一个在`0`到`graph.length-1`之间的整数。