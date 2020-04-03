#include"string_func.h"

// 8. ×Ö·û´®×ª»»ÕûÊý (atoi)
int max_int = 2147483647;
int myAtoi(string str) {
	int size = str.size();
	int res = 0;
	int sign = 1;
	for (int i = 0; i < size; i++) {
		if (str[i] == ' ') continue;
		if (str[i] == '+') continue;
		if (str[i] == '-') {
			sign = -1;
			continue;
		}
		if (str[i] >='0' && str[i] <= '9') {
			if ((res > max_int / 10) || ((res == (max_int / 10)) && ((sign && str[i] > '7') || (!sign && str[i] > '8')))) {
				if (sign == 1) res = max_int;
				else res = max_int + 1;
				break;
			}
			else {
				res = res * 10 + (str[i] - '0');
			}
		}
		else break;
	}
	return res * sign;
}
