[重建二叉树]()



[不用加减乘除做加法]()

```C++
int Add(int num1, int num2){
        return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;
}
```

