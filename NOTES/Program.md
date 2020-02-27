# 编程

### 函数模板：避免冗余

```C++
template<typename T> // <模板那参数表>内容可以是class标识符，常量参数，模板参数
T abs(T x){
    return x<0?-x:x;
}
```

只有能够在函数模板中运算的类型才可以作为类型的实参，自定义的类需要重载模板中的运算符才可以作为实参。

### 类模板

定义：

```C++
template<模板参数表>
class 类名{成员申明}
// 在类模板外定义成员函数
template<模板参数表>
类型名 类名<模板参数标识符列表>::函数名(参数表)
```

### 群体

多个元素组合体，分为线性（有次序，可以直接、顺序、索引访问）和非线性（不同位置顺序表示元素）

#### 直接访问线性群体——数组

物理地址相邻

#### 顺序访问线性群体

- 链表

  - 一种动态数据结构，由结点组成，结点在运行时动态生成，结点包括数据域和指向下一个结点的指针，如果每个结点只有一个后继结点指针则是单链表。（物理地址不相邻）

  - 链表操作：插入，查找，删除，遍历，清空等。

- 栈结构

  - 先进先出，一端访问的线性群体。

  - 状态：栈空、栈满，一般状态
  - 基本操作：初始化、入栈、出栈、清空、访问栈顶元素、检测状态等。

- 队列
  - 一端访问的受限的线性群体
  - 状态：队空、队满，一般状态（特殊队列：循环队列）



## STL

### 基本组件

<img src="img/STL基本组件.png" height=250px>

- 迭代器：泛型指针，可以访问容器中的元素。
- 容器：容纳一组元素的对象（类模板格式）
  - 顺序容器：数组，向量，队列，链表等
  - 有序关联容器：集合，映射
  - 无序关联容器：无序集合，无序映射
- 函数对象：`functional`
- 算法：排序算法，计数算法等，包含 `Algorithm`

### 容器

####  通用功能：

- 用默认构造函数构造空容器

- 支持关系运算符: `==、!=、<、<=、 >、>=`
- `begin()`、`end()` :获得容器首、尾迭代器
- `clear()` :将容器清空
- `empty()` :判断容器是否为空
- `size()` :得到容器元素个数
- `s1.swap(s2)` :将s1和s2两容器内容交换相关数据类型 ( S表示容器类型)
- 相关数据类型：`S::iterator` :指向容器元素的迭代器类型，`S::const_iterator` :常迭代器类型 

#### 顺序容器

 **顺序容器的接口** (不包含单向链表( forward. list )和数组( array ) )：构造函数、赋值函数`assign`，插入函数`insert`，`push_front` (只对list和deque)、`push_back`，`emplace`，`emplace_front`，删除函数`erase`，`clear`，`pop_front`(只对list和deque )，`pop_back`，`emplace_back`，首尾元素的直接访问`front` , `back`，改变大小`resize` 。

- **特性**

  - `vector` 可以扩展的动态数组
    - 容量(capacity) :实际分配空间的大小
    - `s.capacity()` :返回当前容量
    - `s.reserve(n)` :若容量小于n，则对s进行扩展,使其容量至少为n 

  - `deque`适合少量随机访问操作，需要在容器两端进行增删操作
  - `list` 在任意位置插入和删除元素都很快，不支持随机访问
    - 接合(splice)操作：`s1.splice(p, s2, q1, q2)` :将`s2`中`[q1, q2)`移动到`s1`中`p`所指向元素之前 
  - `forward_list` 单向链表每 个结点只有指向下个结点的指针，没有简单的方法来获取一个结点的前驱;
    -  定义了`insert_after`、`emplace_after`和e`rase_after`操作，对当前结点之后进行操作
    - 不支持size操作。
  - `array` 的对象的大小是固定的 ，定义时除了需要指定元素类型，还需要指定容器大小。不能动态地改变容器大小 

- **PS：容器选择**
  - `vector`适合需要执行大量随机访问操作，并且只需要向容器队尾增加新元素
  - `deque`适合少量随机访问操作，需要在容器两端进行增删操作
  - `list/forward_list`适用于不需要随机访问但是需要在中间进行增删操作
  - `array`是一种相对安全的数组更容易使用

- 插入迭代器：前插，后插和任意插入。

  ```C++
  list<int> s; back_inserter iter(s);
  *(iter++) = 5;// 将元素直接插入
  ```

- 适配器：以顺序容器为基础构建的数据结构，包括栈模板、队列模板和优先级队列模板。

#### 关联容器

**特点**： 每个关联容器都有一个键(key)。可以根据键高效地查找元素接口。接口包括插入: `insert`，删除:`erase`，查找: `find`，定界 : `lower_bound`、`upper_bound`、`equal_range`，计数: `count` 。

- 单重关联容器
  - 集合：存储一组无重复元素的容器，集合是有序的。
  - 映射：按照键来查找存在以及得到附加的值。
- 多重集合和多重映射

<img src="img\关联容器.png" height="250px">



## 函数对象

```C++
int mult(int x, int y) { return x * y; };	//定义一个普通函数
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elements in a is "
		<< accumulate(a, a + N, 1, mult)<< endl;	//将普通函数mult传递给通用算法
	return 0;
}
class MultClass	{  //定义MultClass类，函数类对象
public:
	int operator() (int x, int y) const { return x * y; }	//重载操作符operator()
};
int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elements in a is "
		<< accumulate(a, a + N, 1, MultClass())<< endl;	//将类multclass传递给通用算法
	return 0;
}
// STL标准库函数对象用法
sort(a.begin(), a.end(), greater<int>());
accumulate(a, a + N, 1, multiplies<int>())
```

**STL提供了函数对象包括算数运算和关联逻辑运算等**

