//������������¥�ݡ���Ҫ n ������ܵ���¥����
//
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
//
//ע�⣺���� n ��һ����������
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//��̬�滮
//dp[i]:�����˵���i��̨�׵ķ�����
//��ϵʽ��dp[i] = dp[i-1]+dp[i-2];
//��ʼֵ��dp[0]=1,dp[1]=1;
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