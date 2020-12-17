/*
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
注意:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
 */
 #include<iostream>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<tuple>

 using namespace std;
 vector<int> prices {1, 3, 2, 8, 4, 9};
 //这是一道动态规划的问题
 /*
 dp[i][0]:代表的是第 i 天手里没有股票时的最大收益
 转移方程：dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
 dp[i][0],可能时 i-1 天时手里没有股票的最大收益，也有可能时i-1天手里还有股票，然后在i 天卖出，则加 i 天收益，减去费用，这两者取最大值
 */
 /*
 dp[i][1]:代表的是第 i 天手里有股票时的最大收益
 转移方程： dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
 dp[i][1] ，可能在i-1天时手里还有股票且情况不变，也有可能时i-1天时，手里已经没有股票，在 i 天时候购入，则dp[i-1][0]减去i天的股票价格，两者的最大值
 */
 #include<utility>
 int maxProfit(vector<int>& prices, int fee) 
 {
     int n = prices.size();
    //  vector<vector<int>> dp(n,vector<int>(2));
    //  dp[0][0] = 0;//初始时为0；
    //  dp[0][1] = -prices[0];//初始时为第一次付出去的钱

    //  for(int i=1;i<n;++i)
    //  {
    //      dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
    //      dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
    //  }
    //  return dp[n-1][0];

    //用两个变量来记录
    int sell = 0;
    int buy = -prices[0];
    pair <int,int> p1;
   for(int i=1;i<n;i++)
    {
        p1 = make_pair(max(sell, buy + prices[i] - fee), max(buy, sell - prices[i]));
        tie(sell,buy) = p1;
    }
    return sell;


 }
 int main()
 {
     int ans = 0;
     ans = maxProfit(prices,2);
     cout<<ans<<endl;
     system("pause");
     return 0;
 }
