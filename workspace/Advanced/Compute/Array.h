#pragma once
#ifndef ARRAY_H_
#define ARRAY_H_


template <class T>
class Array
{
public:
	Array(int s=50);
	Array(const Array<T> &a);
	~Array();
	
	// 重载
	Array<T> & operator = (const Array<T> &rhs);
	T & operator [] (int i); // 重载下标运算符
	const T & operator [] (int i) const;
	operator T * (); // 重载指针运算
	operator const T * () const; // 处理常指针
	int getSize() const;
	void resize(int s);

private:
	T* list; // 存放动态分配数组内存的首地址
	int size;
};

#endif // !ARRAY_H_