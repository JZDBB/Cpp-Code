# 数据共享和传输

## 作用域

- 函数原型作用域`函数名(参数)`

- 局部(块)作用域`{内部}`

- 类作用域`class 内函数和类体`——类作用域以外访问成员（静态和非静态）

- 文件作用域`cpp文件内`

- 命名空间作用域

  PS：注意标识符的**可见性**

#### 	demo

```C++
int i;
int main(){
    i = 5;
    {
        int i;
        i=7;
        cout<<"i = "<< i <<endl;
    }
    cout<<"i = "<< i <<endl;
    return 0;
} // 结果 ——> i=5 i=7
```

## 生存期

- 静态生存期——和程序运行相同，执行离开作用域还会存在，只要不做修改
- 动态生存期——开始于声明点，结束于作用域结束

```C++
int i = 1; // i 为全局变量，静态生存期
void other(){
    static int a = 2;
    static int b; // a,b静态局部变量，具有全局寿命，局部可见，只在第一次进入函数时初始化
    int c =10; // c 为局部变量，动态生存期，每次进入都初始化
    a +=2;i +=32;c+=5;
    cout <<"---OTHER---\n";
    cout << "i:"<<i<<"  a:"<<a<<"  b:"<<b<<"  c:"<<c<<endl;
    b=a;
}
```

## 静态数据成员

采用关键字`static`声明，属于整个类共享。

```C++
class Point{
private:
    int x; int y;
    static int count; // 静态成员统计点个数
public:
    Point(int x=0,int y=0):x(x),y(y){count++;};
    Point(Point &p){x=p.x;y=p.y;count++;};
    ~Point(){count--;}; //构造和析构
    int getX(){return x;}
    int getY(){return y;}
    static void showCount(){cout <<"Objectcount = "<<count<<endl;}
};
```

## 友元

将一个模块声明为另外一个模块的友元由此能够引用模块里本应被隐藏的信息——友元函数/友元类

- 友元函数：关键字`friend`修饰，能够通过对象名访问`private`和`protected`。对象作为参数传递

  - ```C++
    class Point{
    private:
        int x;
        int y;
    public:
        Point(int x=0,int y=0):x(x),y(y){};
        Point(Point &p){x=p.x;y=p.y;};
        ~Point(){};
        int getX(){return x;}
        int getY(){return y;}
        friend float dist(Point &a,Point &b);// 传引用作为参数，双向传递
        friend float dist(const Point &a,const Point &b);//const不可修改，单向只读引用
    };
    ```

- 友元类：能访问类内数据 —— 友元关系是单向的

  - ```C++
    class A{
        friend class B;
    public:
        void display(){cout<<x<<endl;}
    private:
        int x;
    };
    
    class B{
    public:
        void set(int i);
        void display();
    private:
        A a;
    };
    void B::set(int i){a.x=i;}
    void B::display(){a.display();}
    ```

## 常类型

- 常对象：`const 对象名` 不能改变和更新

- 常成员：

  - 常成员函数：`函数名（参数表） const` 

  ```C++
  class R{
      public:
      R(int r1, int r2):r1(r1),r2(r2){}
      void print();
      void print() const;
      private:
      int r1, r2;
  }
  void R::print(){cout<<r1<<":"<<r2;}
  void R::print() const{cout<<r1<<";"<<r2;}
  
  int main(){
      R a(5,4);
      a.print(); // 调用 void print()
      const R b(20,52);
      b.print(); // 调用 void print() const
      return 0;
  }    
  
  ```

  - 常数据成员：`const` 修饰的数据成员

  ```C++
  class A{
      public:
      A(int i);
      void print();
      private:
      const int a;
      static const int b; // 静态数据成员
  }
  const int A::b=10;
  A::A(int i):a(i){}
  void A::print(){cout<<a<<";"<<b;}
  ```

- 常数组

- 常指针

## 外部变量&外部函数

- 外部变量：文件作用域中定义的变量默认为外部变量，可以被其他文件用`extern` 关键字声明使用
- 外部函数：使用中需要在文件中声明函数。
- 命名空间使用`namespace`

## 编译预处理

- `#include`
- `define` 宏定义——符号&标记
- `undef` 删除宏定义
- `#if 程序正文1 elif 程序正文2  else 程序正文3 #endif` 条件编译指令
- `ifdef` 和 `ifndef` 是否定义了某个标识符

PS：为了避免重复包含在使用编译预处理指令

#### demo

`client.h`

```C++
#ifndef CLIENT_H_
#define CLIENT_H_
程序正文
#endif
```

