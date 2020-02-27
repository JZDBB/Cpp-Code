#pragma once
#include"Node.h"
template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T> &L);
	~LinkedList();

	LinkedList<T> & operator = (const LinkedList<T> &L);
	int getSize() const;
	bool isEmpty() const;
	void reset(int pos = 0);
	void next();
	bool endOfList() const;
	int currentPosition() const;
	void insertFront(const T &item);
	void insertRear(const T &item);
	void insertBefore(const T &item);
	void insertAfter(const T &item);
	T deleteFront();
	void deleteCurr();
	T& data(); // 返回当前结点成员数据的引用
	const T& data() const;// 返回当前结点成员数据的常引用
	void clear();


private:
	Node<T> *front, *rear; // 表头表尾
	Node<T> *prevP, *currP; // 当前位置指针
	int size, position;
	Node<T> *newNode(const T &item, Node<T> *ptrNext = NULL);
	void freeNode(Node<T> *p);
	void copy(const LinkedList<T> &L); // 将L复制到当前列表，被复制构造函数和“=”操作符调用


};

