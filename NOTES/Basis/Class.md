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

### 类组合

- 类似于部件组装，将一些类作为新定义类的对象，需要对本类和对象成员初始化。

- 成员对象构造函数调用顺序——先声明先构造——**基本类写默认构造函数便于重用**

- 前向引用声明——只能使用类符号，不能做具体操作（不是万能的）

  - ```C++
    class B;//前向引用声明
    class A{public:void f(B b)}
    class B{public:void g(A a)}
    ```

### 结构体

特殊的类，默认公有
```C++
struct Student{
	int num;
    string name;
    char sex;
    int age;
}
```

### 联合体

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

### 枚举类

优势：强作用域，

```C++
enum class 枚举类型名：底层类型{枚举值列表}// 没有指定底层类型默认为int
//使用Type枚举值General——可以防止重名
Type::General
// 例子
enum class Side{Right, Left}
enum class Thing{Right, Wrong} // 变量名不冲突
```



## 继承和派生

- 保持已有类构造新的类——继承
- 在已有类基础上新增自己的特性——派生
- 被继承的已有类为**基类/父类**，派生的新类为**派生类/子类**，还有**直接/间接基类**

语法：

单继承：`class 派生类名:继承方式 基类名 {成员声明}`
多继承：`class 派生类名:继承方式1 基类名1, 继承方式2 基类名2...{成员声明}`

- 吸收：默认情况下派生类包含除了构造和析构的所有成员。
- 改造：同名成员改造和覆盖
- 新增：增加新扩展功能

### 继承方式

区分在于：派生类成员和派生类对象的访问权限

- 公有继承
  - 成员函数可以访问`public`和`protected`成员，`private`不可直接访问
  - 通过派生类对象只能访问`public`成员
- 私有继承
  - 成员函数可以访问`public`、`protected` 但继承以后都是`private`成员，同时`private`不可直接访问
  - 派生对象不能直接访问任何基类继承的成员
- 保护继承
  - 成员函数可访问`public`、`protected` 但继承以后都是`protected` 成员，同时`private`不可直接访问
  - 派生对象不能访问基类任何成员。只能访问新增的成员

### 构造函数

- 继承基类的构造函数`using B::B`
- 不继承基类构造函数
  - 新增成员用构造函数初始化，继承的成员自动调用构造函数初始化，派生类构造函数需要向基类构造函数传递参数。
  - `派生类名::派生类名(基类所需参数, 本类成员所需形参):基类名(参数表), 本类成员初始化列表`

### 复制构造函数

复制构造函数只能接受一个参数即用来初始化派生类，也要传递给基类复制构造函数。由于基类的赋值构造函数形参为基类的引用，实参可以是派生类对象的引用。
`C::C(const C &c1):B(c1){...}`

### 析构函数

析构是先析构派生类，在析构基类——和构造相反。

### 访问基类成员

若未特别限定，则通过派生类对象使用同名成员，如果派生类对象访问基类中被隐藏的同名成员，应该使用基类名加作用不操作符来限定。

### 虚基类

继承多个基类，这些基类有共同的基类，由此产生冗余和不一致性。
- 虚基类声明：`virtual`
- 作用：能够解决多继承中发生多次同一基类继承多次产生的二义性，同时减少冗余
- 在第一级继承的时候就要将共同基类设计为虚基类。
- 建议公用软件包慎用虚基类



## 多态

### 虚函数

- 用`virtual` 说明的函数为虚函数，虚函数是实现运行时**多态性**的基础。
- 虚函数是动态绑定的函数，必须是非静态成员函数，经过派生后可以实现运行多态。
- 一般成员函数和析构函数可以是虚函数，构造函数不能是虚函数。
  - 一般成员函数：声明在类定义中的函数原型声明，派生类中可以对基类成员函数进行覆盖，一般不声明为内联函数，因为虚函数是动态的，内联函数是静态的
  - 虚函数：大多在构造函数有指针时，在析构函数指针`delete` 时使用，用以进行内存空间释放。

### 动态绑定

- 虚表：每一个多态类都有一个虚表，虚表中有当前类的各个虚函数入口地址，每个对象有指向当前类的虚表的指针（虚指针）
- 动态绑定是通过虚表实现的。

动态绑定虚表示意图：

<img src="img/虚表示意图.png" height=250px>





### 纯虚函数

基类中声明的虚函数，在基类中没有定义具体操作，要求派生类**根据需要自己定义**(如几何图形类的求面积函数)

带有纯虚函数的类称为**抽象类**：保证派生类具有统一要求，抽象类只能作为基类用，不能定义对象，只能定义对应的指针

格式：`virtual 函数类型 函数名(参数表)=0;`



##### ==PS:==

- `override`：用以检查基类中与派生类声明`override`的函数有相同函数签名，若不存在，则会报错
- `final`：不允许声明了`final`的类被继承和覆盖
- 虚函数和虚基类不同：
  - 虚基类是解决类成员标识符二义性和冗余问题
  - 虚函数是实现动态多态性的基础


