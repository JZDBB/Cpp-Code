# 面向对象

## 基本概念

- 抽象：对同一类对象的共同属性和行为的概况，形成类。
  - 数据抽象：对象的属性和状态
  - 代码抽象：共同行为特征和功能
- 封装：将抽象出的数据和代码结合为整体——为了简化和方便调用接口
- 继承
- 多态

### 设计类

该类的“合法值”，有什么函数，怎么创建和销毁，初始化和赋值，参数如何传递等。


## 构造和析构

- **构造函数**用于描述初始化，表示对象创建时的特定初始状态
  - 函数名同类名
  
  - 不能定义返回值类型，不能有return语句
  
  - 可以有形参也可以没有，可以带默认参数

  - 可以是内联函数，可以重载
  
  - 类定义时，如果没有构造函数，编译器会自动生成，默认初始化
  
  - 复制构造函数：用已存在的对象初始化同类型新对象
  
    - 定义对象时，以本来一个对象作为初始值
    - 形参是类对象时发生复制构造
    - 返回为类对象时
  
    ```C++
    // 复制构造函数
    	Point a;
    	Point b(a);//第一种情况
    	cout << b.getX() << endl;
    	fun1(b);//第二种情况
    	b = fun2();//第三种情况
    	cout << b.getX() << endl;
    ```
  
- **析构函数** 做对象删除前的清洗工作

### Demo

`clock.hpp` & `clock.cpp`


```c++
class Clock //类名
{
public:  // 共有成员——外部访问接口
    Clock()==default;// 提示编译器提供默认构造函数
    Clock(int newH, int newM, int newS);
    Clock(const Clock&c)=delete;//提示编译器不生成默认复制构造函数
	void setTime(int newH, int newM, int newS);
	void showTime();
private: // 私有成员——只允许本类函数访问
	int hour, minute, second;
protected:  // 保护型成员——继承和派生用到
};
// 委托构造函数借用其他构造函数执行初始化
Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS){}
Clock::Clock(0,0,0){}
```

## 类组合

- 类似于部件组装，将一些类作为新定义类的对象，需要对本类和对象成员初始化。

- 成员对象构造函数调用顺序——先声明先构造——**基本类写默认构造函数便于重用**

- 前向引用声明——只能使用类符号，不能做具体操作（不是万能的）

  - ```C++
    class B;//前向引用声明
    class A{public:void f(B b)}
    class B{public:void g(A a)}
    ```

## 结构体

特殊的类，默认公有
```C++
struct Student{
	int num;
    string name;
    char sex;
    int age;
}
```

## 联合体

联合体目的在于存储空间共用，公有、私有、保护成员共用一个内存单元，不能同时有效

```C++
class ExamInfo{
private:
    string name;
    enum {GRADE, PASS, PERCENTAGE} mode; //计分方式
union {
	char grade;
    bool pass;
    int percent;}
}
// 构造函数以及其他操作要有三种
ExamInfo(string name, char grade):name(name),mode(GRADE),grade(grade){}
ExamInfo(string name, bool pass):name(name),mode(PASS),pass(pass){}
ExamInfo(string name, int percent):name(name),mode(PERCENTAGE),percent(percent){}
```

## 枚举类

优势：强作用域，

```C++
enum class 枚举类型名：底层类型{枚举值列表}// 没有指定底层类型默认为int
//使用Type枚举值General——可以防止重名
Type::General
// 例子
enum class Side{Right, Left}
enum class Thing{Right, Wrong} // 变量名不冲突
```








