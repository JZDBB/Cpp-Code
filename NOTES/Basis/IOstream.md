# IO stream

程序与外界信息交换是存在程序对象和文件对象（文件可以是磁盘文件也可以是键盘输入等）

流对象是程序和文件相连接的抽象，读操作为流提取，写操作为流插入。

## 输出流

`ostream、ofstream、ostringstream` 输出流

`cout(标准流)、cerr(无缓冲)、clog(有缓冲，缓冲满输出)` 输出流对象

标准输出换向

#### 构造输出流对象

成员函数包括`open、put、write、seekp、tellp、close和错误处理`

- `ofstream` 支持磁盘文件输出，可以指定文件打开模式，默认`ios_base::out`，构造方法

  - 在构造函数中指定文件名，能自动打开`ofstream myFile("filename");`
  - 调用默认构造函数之后使用`open`成员函数打开 `myFile.open("filename");`
  
- `ostream`文本文件输出：输出到显示器等

  - 插入运算符`<<` 操纵符（`ios_base`指定输出格式、宽度、高度、默认进制）

    - 设置宽度和精度

    ```C++
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    
    for(int i = 0; i < 4; i++) {
        cout.width(10); 
        cout << values[i] << endl; // (1)
        cout << setw(6) << names[i] << setw(10) << values[i] << endl;//(2)默认右对齐
        cout << setiosflags(ios_base::left) << setw(6) << names[i]<< resetiosflags(ios_base::left)<< setw(10) << values[i] << endl; // 左对齐和右对齐
        // 输出精度
    }
    ```
- `ostringstream`构造字符串输出

#### 构造输入流对象

- `stream`类最适合用于顺序文本模式输入。`cin`是其实例。相关函数包括`open、get（和>>差别在于get包括空白符）、getline、read、seekg、tellg、close` 等
- `ifstream`类支持磁盘文件输入。可以指定文件打开模式，默认`ios_base::out`，构造方法
  - 在构造函数中指定文件名，能自动打开`ofstream myFile("filename");`
  - 调用默认构造函数之后使用`open`成员函数打开 `myFile.open("filename");`
- `istringstream` 



#### 输入输出流

从`iostream` 派生出的，`fstream`和`stringstream` 类。



## 移动读取指针

`tellg & tellp` 获取读写指针的位置和 `seekg & seekp` 设置读写指针的位置

**函数原型**

```C++
ostream & seekp (int offset, int mode);
istream & seekg (int offset, int mode);
// offset 代表到文件开头的距离，开头为0，按照字节为单位计数
// mode 为模式设置 
// 	  ios::beg -> 从头开始，offset>=0
//    ios::cur -> 从当前位置开始，offset可以任意只要不超出范围
//    ios::end -> 从尾开始，offset<=0
int tellg();
int tellp();
```

