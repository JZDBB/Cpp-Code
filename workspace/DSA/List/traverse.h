#pragma once
//遍历，依次实施visit操作（函数指针，只读或局部性修改）
template <typename T>
void List<T>::traverse(void(*visit) (T&)) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}
//遍历，依次实施visit操作（函数对象，可全局性修改）
template <typename VST>
void traverse(VST & visit) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}