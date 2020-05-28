[重建二叉树]()

```C++
TreeNode* Tree(vector<int> pre,vector<int> vin, int l1, int r1, int l2, int r2){
    TreeNode* root;
    if(l1>r1) return nullptr;
    root = new TreeNode(pre[l1]);
    int i;
    for(i=l2;i<=r2;i++){
        if(vin[i]==root->val) break;
    }
    root->left = Tree(pre, vin, l1+1, l1+i-l2, l2, i-1);
    root->right = Tree(pre, vin, l1+i-l2+1, r1, i+1, r2);
    return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() == 0 || vin.size() == 0)
        return nullptr;
    return Tree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
}
```

[不用加减乘除做加法](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
int Add(int num1, int num2){
        return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;
}
```

[构建乘积数组](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
vector<int> multiply(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n);
    int mul = 1;
    for(int i=0;i<n;i++){
        res[i] = mul;
        mul *= A[i];
    }
    mul = A[n-1];
    for(int i=n-2;i>=0;i--){
        res[i] = mul * res[i];
        mul *= A[i];
    }
    return res;
}
```

[和为S的连续正数序列](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
vector<vector<int> > FindContinuousSequence(int sum) { // 滑动窗口
    int l = 1;  int r = 1;  int Sum = 1;  vector<vector<int>> res;
    while(l<=r){
        r++;   Sum+=r;
        while(Sum>sum){
            Sum -= l;  l++;
        }
        if(Sum==sum && l!=r){
            vector<int> tmp;
            for(int i=l;i<=r;i++) tmp.push_back(i);
            res.push_back(tmp);
        }
    }
    return res;
}
```

[滑动窗口的最大值](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&tPage=4&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	if (num.empty() || size > num.size() || size < 1) return {}; // 越界问题！！
	vector<int> s;	vector<int> res;	int count = size;
	for (int i = 0; i < num.size(); i++) {
		if (count > 0) {
			if (s.empty()) s.push_back(num[i]);
			else { // 挤掉比自己小的数
				while (s.size() >= 1 && s.back() < num[i])	s.pop_back();
				s.push_back(num[i]);
			}
			count--;
		}
		else {
			res.push_back(s[0]);
			if (num[i - size] == s[0])	s.erase(s.begin());
			while (s.size() >= 1 && s.back() < num[i]) 	s.pop_back();
			s.push_back(num[i]);
		}
	}
	res.push_back(s[0]);
	return res;
}
```

[丑数](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
int GetUglyNumber_Solution(int index) {
    if(index<7) return index;
    int num; int n2 = 0; int n3 = 0; int n5 = 0;
    vector<int> Vec = {1};
    for(int i=0;i<index;i++){
        num = min(Vec[n2]*2, min(Vec[n3]*3, Vec[n5]*5));
        Vec.push_back(num);
        if(num == Vec[n2]*2) n2++;
        if(num == Vec[n3]*3) n3++;
        if(num == Vec[n5]*5) n5++;
    }
    return Vec[index-1];
}
```

[两个链表的公共节点]()

```C++
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(!pHead1|!pHead2) return nullptr;
    ListNode* p1 = pHead1; ListNode* p2 = pHead2;
    while(p1!=p2){
        p1 = p1==NULL? pHead2: p1->next;
        p2 = p2==NULL? pHead1: p2->next;
    }
    return p1;
}
```

[对称二叉树]()

```C++
bool isSymmetrical(TreeNode* pRoot){
    if(!pRoot) return true;
    queue<TreeNode*> Q;  Q.push(pRoot->left);  Q.push(pRoot->right);
    while(!Q.empty()){
        TreeNode* p = Q.front(); Q.pop();
        TreeNode* q = Q.front(); Q.pop();
        if(!p&&!q) continue;
        if(!p||!q) return false;
        if(p->val!=q->val) return false;
        Q.push(p->left);   Q.push(q->right);
        Q.push(p->right);  Q.push(q->left);
    }
    return true;
}
```

[机器人运动]()

```C++
int get(int x) {
    int res = 0;
    for (; x; x /= 10) res += x % 10;
    return res;
}
int movingCount(int threshold, int row, int col){
    if(threshold<0) return 0;  if (!threshold) return 1;
    queue<pair<int, int>> Q; int dx[2] = { 0,1 }; int dy[2] = { 1,0 };
    vector<vector<int>> V(row, vector<int>(col, 0));
    Q.push(pair<int, int>(0, 0)); V[0][0] = 1; int ans = 1;
    while (!Q.empty()) {
        int x0 = Q.front().first; int y0 = Q.front().second; Q.pop();
        for (int i = 0; i < 2; i++) {
            int x = x0 + dx[i]; int y = y0 + dy[i];
            if (x<0||x>=row||y<0||y>=col||V[x][y]||get(x)+get(y)>threshold) continue;
            Q.push(pair<int, int>(x, y));
            V[x][y] = 1;
            ans++;
        }
    }
    return ans;
}
```

