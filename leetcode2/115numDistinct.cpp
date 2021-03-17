/*
@time:2021-3-17
@author:gyl
@series:每日一题(hard)
@problem：给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
*/


/*
这题一看就是动态规划的，不会做；
参考官方的示例给出结果
*/

/*
动态规划:建立dp[i][j]:
s[i](从i到后面的字符串)
若与t[j](从j到后面的字符串)相同，
则dp[i][j]=1;反之为0

迭代公式  dp[i][j] = dp[i+1][j+1]+dp[i+1][j];(s[i]=t[j])
 dp[i][j] = dp[i+1][j];(s[i]!=t[j])
*/
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int numDistinct(string s, string t) 
{
    int m = s.length();
    int n = t.length();
    vector<vector<long>> dp(m+1,vector<long>(n+1));//创建dp数组；PS：+1防止溢出且配合字符串大小
    for(int i=0;i<=m;i++)
    {
        dp[i][n]=1;//若j=n,则t字符为空，则它肯定是S的子串。
    }

    for(int i=m-1;i>=0;i--)
    {
        char sch = s.at(i);//从s的最后开始扫描
        for(int j=n-1;j>=0;j--)
        {
            char tch = t.at(j);
            if(sch==tch)
            {
                dp[i][j]=dp[i+1][j+1]+dp[i+1][j];//若当前字符相等，则有前一个字符也相等和t当前字符和s的前一个字符相等的情况。
            }
            else
            {
                dp[i][j] = dp[i+1][j];//当前不相等，则数值等于前一种情况；
            }
        }
    }
    return dp[0][0];//返回两个字符从头开始的数量。
}
