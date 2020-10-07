//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/valid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <stack>>
//使用栈的先进后出
//首先：如果是[,{,(都入栈
//然后：遇到],},)与栈顶进行匹配，如果匹配成功则pop,反之直接false
//PS:仅有左括号或剩下左括号落单，则是在匹配结束查看栈是否为空，若为空则true，反正false
	//仅有右括号或第一个符号为右括号：则是在首先遇到右括号时，首先判断栈是否为空
using namespace std;
int main()
{
	stack<char> brackets;
	bool fine = true;
	string s = "]}]";

	int i = 0;
	while (i < s.size())
	{
		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
		{
			brackets.push(s[i]);
		}
		else
		{
			if (s[i] == ']' || s[i] == ')' || s[i] == '}')
			{
				if (brackets.empty())
				{
					fine = false;
					break;
				}
			}

			if (s[i] == ']'&&brackets.top() == '[')
			{
				brackets.pop();
			}
			else if (s[i] == ')'&&brackets.top() == '(')
			{
				brackets.pop();
			}
			else if (s[i] == '}'&&brackets.top() == '{')
			{
				brackets.pop();
			}
			else
			{
				fine = false;
			}

		}
		i++;
	}
	if (!brackets.empty())
	{
		fine = false;
	}
	std::cout << boolalpha << fine << endl;



	system("pause");
	return 0;
}