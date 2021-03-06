﻿//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//
//示例 1 :
//
//输入: 123
//	输出 : 321
//	示例 2 :
//
//	输入 : -123
//	输出 : -321
//	示例 3 :
//
//	输入 : 120
//	输出 : 21
//	注意 :
//
//	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231, 231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/reverse-integer
//	//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//PS:不能转字符串，不能转字符串。不能转字符串
int reverse(int x)
{
	int ans = 0;
	int pop = 0;
	while (x != 0)
	{
		pop = x % 10;//每次取出当前数字的个位
		x = x / 10;//抛出最后一位后剩下的数字
		//为了预判是否越界，则在上一位进行判断
		if (ans > INT_MAX / 10 || (ans == INT_MAX/10 && pop > 7))
			return 0;
		if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8))
			return 0;
		ans = ans * 10 + pop;
	}
	return ans;
}
int main()
{
	int x = 1564789657;
	int ans = 0;
	ans = reverse(x);
	std::cout << ans << endl;
	system("pause");
	return 0;
}