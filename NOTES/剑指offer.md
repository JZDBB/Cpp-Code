[重建二叉树]()



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

