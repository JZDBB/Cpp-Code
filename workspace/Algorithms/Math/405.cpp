#include"Math.h"

// 405. 数字转换为十六进制数
string toHex(int num) {
	string hexs = "0123456789abcdef";
	string res = "";
	if (num == 0){
		return "0";
	}
	//32位即可，即最终输出十六进制的长度不大于8
	while (res.size() < 8 && num){
		res = hexs[num & 0xf] + res;
		num >>= 4;
	}
	return res;
}
