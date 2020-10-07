//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//动态规划
//dp[i]:代表了到第i阶台阶的方法。
//关系式：dp[i] = dp[i-1]+dp[i-2];
//初始值：dp[0]=1,dp[1]=1;
int climbStairs(int n)
{
	vector<int> dp(n+1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];

}
int main()
{
	int ans = 0;
	int n = 4;
	ans = climbStairs(n);
	std::cout << ans << endl;
	system("pause");
	return 0;
}