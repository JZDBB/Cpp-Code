#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<string>
#include<list>
using namespace std;

//#include"LinkedList.h"
//#include"Array.h"
#include"Cell.h"


// 函数模板
//template <typename T>
//class array
//{
//public:
//	template <typename T>//因为友元函数是类外函数，所以得另外定义一个函数模板
//	friend ostream &operator << (ostream &, T<T1> &);//输出矩阵
//private:
//	T array;
//};
//template<typename T1>
//ostream &operator<<(ostream &OUT1, T<T1> &M)
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			OUT1 << M.array[i][j];
//			cout << ' ';
//		}
//		cout << endl;
//	}
//	return OUT1;
//}
//template<class T>
//void outputArray(const T *array, int count) {
//	for (int i = 0; i < count; i++)
//		cout << array[i] << " ";
//	cout << endl;
//}

// 例子STL
double square(double x) {
	return x * x;
}

//将来自输入迭代器p的n个T类型的数值排序，将结果通过输出迭代器result输出
template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	//通过输入迭代器p将输入数据存入向量容器s中
	vector<T> s;
	for (; first != last; ++first)
		s.push_back(*first);
	//对s进行排序，sort函数的参数必须是随机访问迭代器
	sort(s.begin(), s.end());
	//将s序列通过输出迭代器输出
	copy(s.begin(), s.end(), result);
}


// 模拟细胞分裂 queue

class Cell;




int main() {
	// 函数模板——debug
	/*const int A = 8, B = 8, C = 20;
	int a[A] = {1, 2, 3,4 ,5 ,6 ,7, 8};
	double b[B] = { 1.2, 3.3, 5.6,1.2, 3.3, 5.6, 4.5,6.7 };
	char c[C] = "Welcome!";
	outputArray(a, A);
	outputArray(b, B);
	outputArray(c, C);*/

	// 链表 ——debug
	/*LinkedList<int> list;
	for (int i = 0; i < 10; i++)
	{
		int item;
		cin >> item;
		list.insertFront(item);
	}
	cout << "List:";
	list.reset();
	while (!list.endOfList)
	{
		cout << list.data() << " ";
		list.next();
	}*/

	// STL例子
	//从标准输入读入若干个实数，分别将它们的平方输出
	/*transform(istream_iterator<double>(cin), istream_iterator<double>(),
		ostream_iterator<double>(cout, "\t"), square);
	cout << endl;*/

	//将s数组的内容排序后输出
	//double a[5] = { 1.2, 2.4, 0.8, 3.3, 3.2 };
	//mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	//cout << endl;
	////从标准输入读入若干个整数，将排序后的结果输出
	//mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	//cout << endl;


	// 顺序容器——vector/deque

	//istream_iterator<int> i1(cin), i2;	//建立一对儿输入流迭代器
	//vector<int> s1(i1, i2);	//通过输入流迭代器从标准输入流中输入数据
	//sort(s1.begin(), s1.end());			//将输入的整数排序
	//deque<int> s2;
	////以下循环遍历s1
	//for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter) {
	//	if (*iter % 2 == 0)	//偶数放到s2尾部
	//		s2.push_back(*iter);
	//	else				//奇数放到s2首部
	//		s2.push_front(*iter);
	//}
	////将s2的结果输出
	//copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;


	// 顺序容器——链表拼接

	//string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
	//string names2[] = { "Bob", "David", "Levin", "Mike" };
	//list<string> s1(names1, names1 + 4); //用names1数组的内容构造列表s1
	//list<string> s2(names2, names2 + 4); //用names2数组的内容构造列表s2
	////将s1的第一个元素放到s2的最后
	//s2.splice(s2.end(), s1, s1.begin());
	//list<string>::iterator iter1 = s1.begin(); //iter1指向s1首
	//advance(iter1, 2); //iter1前进2个元素，它将指向s1第3个元素
	//list<string>::iterator iter2 = s2.begin();  //iter2指向s2首
	//++iter2; //iter2前进1个元素，它将指向s2第2个元素
	//list<string>::iterator iter3 = iter2; //用iter2初始化iter3
	//advance(iter3, 2); //iter3前进2个元素，它将指向s2第4个元素
	////将[iter2, iter3)范围内的结点接到s1中iter1指向的结点前
	//s1.splice(iter1, s2, iter2, iter3);
	////分别将s1和s2输出
	//copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	//cout << endl;
	//copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	//cout << endl;


	// 模拟细胞分裂
	srand(static_cast<unsigned>(time(0)));
	int t;	//模拟时间长度
	cout << "Simulation time: ";
	cin >> t;
	cellQueue.push(Cell(0));	//将第一个细胞压入优先级队列
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split();	//模拟下一个细胞的分裂
		cellQueue.pop();			//将刚刚分裂的细胞弹出
	}







	return 0;
}