#include<iostream>
using namespace std;

//求arctan
double arctan(double x) {
	int i = 1;
	double val = 0, item = x;
	while (item >= 1e-15) { //增加终止条件，也就是精度
		val += (i % 2 == 1) ? item : -1 * item;
		i += 1;
		item = item * x*x*(2 * i - 1) / (2 * i + 1);
	}
	return val;
};

// 找回文数
bool symm(unsigned x) {
	unsigned i = x;
	unsigned m = 0;
	while (i > 0) {
		m = m * 10 + i % 10;
		i /= 10;
	}
	return m == x;
}

// 投骰子
enum GameStatus { WIN, LOSE, PLAYING };
int rollDise() {
	int die1 = 1 + rand() % 6; //1-6的随机数
	int die2 = 1 + rand() % 6;
	int sum = die1 + die2;
	cout << "play rolled：" << die1 << "+" << die2 << "=" << sum << endl;
	return sum;
}

// 递归函数
int comm(int n, int k) {
	if (k > n) return 1;
	else if (n == k|| k == 0) return 1;
	else
		return comm(n - 1, k) + comm(n - 1, k - 1);
}

// 汉诺塔问题
void move(char src, char dest) {
	cout << src << " ---> " << dest << endl;
}
void hanoi(int n, char src, char medium, char dest) {
	if (n == 1) move(src, dest);
	else
	{
		hanoi(n - 1, src, dest, medium);
		move(src, dest);
		hanoi(n - 1, medium, src, dest);
	}
}

// 引用传递
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

// 函数重载
int SumOfSquare(int a, int b) {
	return a * a + b * b;
}

double SumOfSquare(double a, double b) {
	return a * a + b * b;
}

double max1(double x, double y) {// 浮点数比较方法
	if (abs(x - y) < 1e-10) return x;// 判断浮点数相等
	if (x >= y)
		return x;
	else
		return y;
}

// constexpr
constexpr int get_size() { return 20; }
constexpr int foo = get_size();

int main()
{
	cout << "Hello World!" << endl;

	// 求pi
	/*double pi;
	pi = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0);
	cout << "The value of pi is:" << pi << endl;*/

	// 找回文数
	/*int a = 121;
	cout << symm(a) << endl;*/

	// 投骰子
	//int sum, mypoint = 0;
	//GameStatus status;
	//unsigned seed;
	////int rollDice();
	//cout << "please enter an unsigned integer:";
	//cin >> seed;
	//srand(seed);
	//sum = rollDise();
	//switch (sum) {
	//case 7:
	//case 11:
	//	status = WIN;
	//	break;
	//case 2:
	//case 3:
	//case 12:
	//	status = LOSE;
	//	break;
	//default:
	//	status = PLAYING;
	//	mypoint = sum;
	//	cout << "point is " << mypoint << endl;
	//	break;
	//}
	//while (status == PLAYING) {
	//	sum = rollDise();
	//	if (sum == mypoint)
	//		status = WIN;
	//	else if (sum == 7)
	//		status = LOSE;
	//}
	//if (status == WIN)
	//	cout << "play wins" << endl;
	//else
	//	cout << "play loses" << endl;

	// 递归问题
	/*int n, k;
	cout << "enter two integer n and k:" << endl;
	cin >> n >> k;
	cout << "result:" << comm(n, k) << endl;*/

	// 汉诺塔问题
	/*int n;
	cout << "enter a integer n:" << endl;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');*/


	// 引用传递
	/*int x = 5, y = 10;
	swap(x, y);
	cout << "x=" << x << "y=" << y << endl;*/

	// 函数重载
	/*int m, n;
	cout << "enter two integer: ";
	cin >> m >> n;
	cout << "Sum of square: " << SumOfSquare(m, n) << endl;
	double x, y;
	cout << "enter two number: ";
	cin >> x >> y;
	cout << "Sum of square: " << SumOfSquare(x, y) << endl;*/

	// constexpr
	// cout << foo << endl;

	return 0;
}