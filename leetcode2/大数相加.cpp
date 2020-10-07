#include <iostream>
#include <string>
using namespace std;
/*
解法1：补全两个大数，利用ASCII码进行相加
*/
string addstirng_one(string strnum1, string strnum2)
{
	while (strnum1.size() > strnum2.size())
		strnum2 = '0' + strnum2;
	while (strnum1.size() < strnum2.size())
		strnum1 = '0' + strnum1;
	char add;
	int carry = 0;
	for (int i = strnum1.size() - 1; i >= 0; i--)
	{
		//相同位置相加再加入进位
		add = strnum1[i] + strnum2[i] - '0' + carry;
		//若和大于9的ASCII码
		if (add > '9')
		{
			strnum2[i] = add - 10;
			carry = 1;
		}
		else
		{
			strnum2[i] = add;
			carry = 0;
		}
	}
	if (carry == 1)
	{
		strnum2 = '1' + strnum2;

	}
	return strnum2;
}
/*
解法2：逐步使得最后一位相加，再判断进位等
*/
string addstirng_two(string strnum1, string strnum2)
{
	string ret;
	int carry = 0;
	for (int i = strnum1.size() - 1, j = strnum2.size() - 1; i >= 0 || j >= 0; i--, j--)
	{
		//此处将carry复制给sum,则在加法时带入进位
		int sum = carry;
		if (i >= 0)
		{
			sum += strnum1[i] - '0';

		}
		else
			sum += 0;
		if (j >= 0)
		{
			sum += strnum2[j] - '0';

		}
		else
			sum += 0;
		ret.insert(ret.begin(), '0' + sum % 10);
		carry = sum / 10;
	}
	if (carry == 1)
	{
		ret.insert(ret.begin(), '1');
	}
	return ret;
}
int main()
{
	int number1 = 123456789562;
	int number2 = 5467895139;
	//int number1 = 123456;
	//int number2 = 45678;

	string strnum1 = to_string(number1);
	string strnum2 = to_string(number2);

	string sum = addstirng_one(strnum1, strnum2);
	string sum2 = addstirng_two(strnum1, strnum2);
	std::cout << sum << endl;
	std::cout << sum2 << endl;


	

	system("pause");

	return 0;
}