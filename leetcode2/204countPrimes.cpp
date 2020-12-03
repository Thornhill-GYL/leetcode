/*
@time:2020-12-3
@author:gyl
@series:每日一题
@problem:统计所有小于非负整数 n 的质数的数量。

 

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*执行用时：
88 ms

74.99%
*/
int countPrimes(int n)
{
    int ans = 0;
    vector<int> isprime(n,1);
    for(int i=2;i<n;i++)
    {
        if(isprime[i]==1)
        {
            ans++;
        }
        if((long long)i*i<n)
        {
            for(int j = i*i;j<n;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
    return ans;

}
int main()
{
    int ans = countPrimes(10);
    vector<int> isPrime(10, 1);
    cout<<ans<<endl;
    system("pause");
    return 0;

}