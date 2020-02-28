#include <iostream>
#include <iomanip>
#include <string>
#include<fstream>
#include<sstream>
using namespace std;

struct SalaryInfo {
	unsigned id;
	double salary;
};

// 字符串输入输出
template <class T>
inline string toString(const T &v) {
	ostringstream os;	//创建输出字符串流
	os << v;			//将变量v的值写入字符串流
	return os.str();	//返回输出流生成的字符串
}
template <class T>
inline T fromString(const string &str) {
	istringstream is(str);	//创建输入字符串流
	T v;
	is >> v;				//从输入字符串流中读取变量v
	return v;				//返回变量v
}


int main() {

	// 输出宽度

	//double values[] = { 1.23, 35.36, 653.7, 4358.24 };
	//string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
	//for (int i = 0; i < 4; i++) {
	//	cout.width(10);
	//	cout << values[i] << endl; // (1)
	//	cout << setw(6) << names[i] << setw(10) << values[i] << endl;
	//	cout << setiosflags(ios_base::left)
	//		<< setw(6) << names[i]
	//		<< resetiosflags(ios_base::left)
	//		<< setw(10) << values[i] << endl; // 左对齐和右对齐
	//}

	// 输出精度

	// 输入操作
	/*char ch;
	while ((ch = cin.get()) != EOF)
		cout.put(ch);
	string line;
	cout << "Type a line terminated by 't' " << endl;
	getline(cin, line, 't');
	cout << line << endl;*/

	// 二进制文件读写 —— 方便调用
	/*SalaryInfo employee1 = { 600001, 8000 };
	ofstream os("payroll", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char *>(&employee1), sizeof(employee1));
	os.close();
	ifstream is("payroll", ios_base::in | ios_base::binary);
	if (is) {
		SalaryInfo employee2;
		is.read(reinterpret_cast<char *>(&employee2), sizeof(employee2));
		cout << employee2.id << " " << employee2.salary << endl;
	}
	else {
		cout << "ERROR: Cannot open file 'payroll'." << endl;
	}
	is.close();*/

	// 字符串输入输出
	/*string str1 = toString(5);
	cout << str1 << endl;
	string str2 = toString(1.2);
	cout << str2 << endl;
	int v1 = fromString<int>("5");
	cout << v1 << endl;
	double v2 = fromString<double>("1.2");
	cout << v2 << endl;*/

	// seekp 定位 —— 找到需要的
	/*int values[] = { 3, 7, 0, 5, 4 };
	ofstream os("integers", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char *>(values), sizeof(values));
	os.close();

	ifstream is("integers", ios_base::in | ios_base::binary);
	if (is) {
		is.seekg(3 * sizeof(int));
		int v;
		is.read(reinterpret_cast<char *>(&v), sizeof(int));
		cout << "The 4th integer in the file 'integers' is " << v << endl;
	}
	else {
		cout << "ERROR: Cannot open file 'integers'." << endl;
	}
	is.close();*/

	// tellg 
	ifstream file("integers", ios_base::in | ios_base::binary);
	if (file) {
		while (file) {
			streampos here = file.tellg();
			int v;
			file.read(reinterpret_cast<char *>(&v), sizeof(int));
			if (file && v == 0)
				cout << "Position " << here << " is 0" << endl;
		}
	}
	else {
		cout << "ERROR: Cannot open file 'integers'." << endl;
	}
	file.close();

		
	return 0;
}