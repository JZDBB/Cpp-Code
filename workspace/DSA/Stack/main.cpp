#include<iostream>
#include<stack>
#include<string>
using namespace std;


// 递归嵌套 —— 括号匹配
bool match(stack<char> S, string str) {
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
			S.push(str[i]);
		}
		else{
			switch (str[i]) {
			case ')': if (S.top() != '(') return false;
					  else break;
			case ']': if (S.top() != '[') return false;
					  else break;
			case '}': if (S.top() != '{') return false;
					  else break;
			default:break;
			}
			S.pop();
		}
	}
	return true;
}


// 中缀表达式求值
char operators[] = { '+', '-', '*', '/', '^', '!', '(', ')', '\0' };
char priority_matrix[][9] = { {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
							{'>', '>', '<', '<', '<', '<', '<', '>', '>'},
							{'>', '>', '>', '>', '<', '<', '<', '>', '>'},
							{'>', '>', '>', '>', '<', '<', '<', '>', '>'},
							{'>', '>', '>', '>', '>', '<', '<', '>', '>'},
							{'>', '>', '>', '>', '>', '>', ' ', '>', '>'},
							{'<', '<', '<', '<', '<', '<', '<', '=', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{'<', '<', '<', '<', '<', '<', '<', ' ', '='} };
int readnum(char* s) {
	int num = s[0];
	while (isdigit(*s)) {
		num = num * 10 + s[0];
		s++;
	}
	return num;
}

int find_index(char c) {
	switch (c) {
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '^': return 4;
	case '!': return 5;
	case '(': return 6;
	case ')': return 7;
	case '\0': return 8;
	default: break;
	}
	return -1;
}

char priority(char c, char* s) {
	int index1 = find_index(c);
	int index2 = find_index(*s);
	return priority_matrix[index1][index2];
}

int calcu(int num1, char op, int num2=0) {
	switch (op) {
	case '+': return num1+num2;
	case '-': return num1 + num2;
	case '*': return num1 + num2;
	case '/': return num1 + num2;
	case '^': return num1 + num2;
	case '!': 
		int num = 1;
		for (int i = 2; i <= num1; i++) num = num * i;
		return num;
	}
	return 0;
}

int compute(char* s) {
	stack<int> opnd;
	stack<char> optr;
	bool flag = false;
	optr.push('\0');
	while (!optr.empty()) {
		if (isdigit(*s)) {
			opnd.push(readnum(s));
		}
		else switch (priority(optr.top(), s)){
		case '>':
			if (optr.top() == '!') {
				int num = calcu(opnd.top(), optr.top());
				opnd.pop(); opnd.push(num);
			}
			else {
				int opnd1 = opnd.top(); opnd.pop();
				int opnd2 = opnd.top(); opnd.pop();
				opnd.push(calcu(opnd2, optr.top(), opnd2));
			}
			optr.pop();
		case '<': optr.push(s[0]);
		case '=': optr.pop();
		default:
			break;
		}
		s++;  
	}
	return opnd.top();
}


int main() {

	/*stack<char> S;
	string str = "{()}[({()})]({()})";
	cout << match(S, str) << endl;*/
	
	char s[] = "(0!+1)*2^(3!+4)-(5-67-(8+9))";
	cout << compute(s) << endl;

	return 0;
}