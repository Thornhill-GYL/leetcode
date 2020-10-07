//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//
//���ܹ��ж�������ͬ��·����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/unique-paths
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//�����Ǿ���Ķ�̬�滮����Ŀ���Ƚϼ򵥣���������Ľ���
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n,0));
	if (m <= 0 || n <= 0)
	{
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;

	}
	for (int j = 0; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}
int main()
{
	int ans = 0;
	ans = uniquePaths(7, 3);
	std::cout << ans << endl;
	system("pause");
	return 0;
}