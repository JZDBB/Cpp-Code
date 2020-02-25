# Q&A

## 左值 & 右值

**左值 (lvalue, locator value)** 表示了一个占据内存中某个可识别的位置（也就是一个地址）的对象。

**右值 (rvalue)** 非左值即右值；是一个 不 表示内存中某个可识别位置的对象的表达式。

```C++
var = 2 // var为左值，2为右值
    
int foo() {return 2;}
int main(){
    foo() = 2; // 错误，foo是确定的返回一个右值，不能作为左值使用
    return 0;
}
int& foo(){
    return 2; // 错误，foo是返回引用，是左值，不应该返回右值
}
```

