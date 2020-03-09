#pragma once
//遍历，依次实施visit操作（函数指针，只读或局部性修改）
template <typename T>
void List<T>::traverse(void(*) (T&)) {

}

template <typename VST> //操作器
void traverse(VST&); //遍历，依次实施visit操作（函数对象，可全局性修改）