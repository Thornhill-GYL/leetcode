//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/unique-paths
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//此题是经典的动态规划的题目，比较简单，不做过多的解释
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