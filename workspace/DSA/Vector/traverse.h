#pragma once
//遍历（使用函数指针，只读或局部性修改）
template <typename T> 
void Vector<T>::traverse(void(*visit) (T&)) //借助函数指针机制
{
	for (int i = 0; i < _size; i++) visit(_elem[i]);
} //遍历向量

//遍历（使用函数对象，可全局性修改）
//template <typename VST> 
//void Vector<T>::traverse(VST& visit)
//{ for (int i = 0; i < _size; i++) visit(_elem[i]); }