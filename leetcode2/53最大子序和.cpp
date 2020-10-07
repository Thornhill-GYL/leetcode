//给定一个整数数组 nums ，找到一个具有最大和的连续子数组
//（子数组最少包含一个元素）
//返回其最大和。
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//动态规划
//dp[i]:代表当前最大的和，i则是取到最大的下标。
//关系式：dp[i] = max(dp[i-1]+nums[i],nums[i])
		//再与当前的最大值比较
//初始值：dp[0] = nums[0]
//函数中 用temp代表dp[i]
int maxSubArray(vector<int>& nums)
{
	int max = 0;
	int temp = 0;
	max = nums[0];
	for (int i = 0; i < nums.size(); i++)
	{
		if (temp + nums[i] > nums[i])
		{
			temp = temp + nums[i];
		}
		else
			temp = nums[i];
		if (temp > max)
		{
			max = temp;
		}
	
	}
	return max;
}
int main()
{
	int ans = 0;
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	ans = maxSubArray(nums);
	std::cout << ans << endl;
	system("pause");
	return 0;
}