/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//动态规划方法
//（1）：dp[i][j]表示的是原始字符中i到j是否为回文串（0，1）。
//（2）：关系式：dp[i][j] = dp[i+1][j-1]&&s[i]==s[j]
//(3):初始条件：原始字符为1的时候，自然为最长回文字符串，为2是，若两个相等，则是，反之，则不是
string longestPalindrome(string s)
{
	int n = s.length();
	//如果字符长度小于2，直接返回
	if (n < 2)
		return s;
	vector<vector<int>> dp(n, vector<int>(n));
	string ans = "";
	int maxlen = 1;
	int begin = 0;
	//单个元素肯定是回文，所以进行初始化。
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	//将字符串想象为一个上三角阵，从计算每一列开始，从而i的取值要小于j
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < j; i++)
		{
			//若i,j位置的元素不等，则为0；
			if (s[i] != s[j])
				dp[i][j] = 0;
			//相等的情况要分为两种情况。
			else
			{
				//第一种：长度为2则肯定是回文
				//这里的i写成1了，错了好多次
				if (j - i < 3)
					dp[i][j] = 1;
				//第二种：则是判断两个字符中间的字符是否为回文
				else
					dp[i][j] = dp[i + 1][j - 1];
			}
			/*判断最长：
				首先满足是回文的条件，其次长度最大*/
			if (dp[i][j] == 1 && j - i + 1 >maxlen)
			{
				maxlen = j - i + 1;
				begin = i;
			}
		}
	}
	ans = s.substr(begin, maxlen);
	return ans;
}
int main()
{
	string s = "eabcb";
	string ans = longestPalindrome(s);
	string text = "";
	text = s.substr(0, 1);
	std::cout<< ans << endl;
	system("pause");
	return 0;
}