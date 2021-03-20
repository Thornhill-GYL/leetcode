/*
@time:2021-03-20
@author:gyl
@serise:offer7
@problem:写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5




*/
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
 int fib(int n) {
        vector<long long int> dp(n+1);
         dp[0] = 0;
         if(n==0)
        {
            return 0;
        }
         dp[1] = 1;
        if(n==1)
        {
            return dp[1];
        }
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
            dp[i] %= 1000000007;//一定要在这取余 不然就会爆
        }
    
        return dp[n];


    }