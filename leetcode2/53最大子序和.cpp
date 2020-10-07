//����һ���������� nums ���ҵ�һ���������͵�����������
//�����������ٰ���һ��Ԫ�أ�
//���������͡�
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
//��̬�滮
//dp[i]:����ǰ���ĺͣ�i����ȡ�������±ꡣ
//��ϵʽ��dp[i] = max(dp[i-1]+nums[i],nums[i])
		//���뵱ǰ�����ֵ�Ƚ�
//��ʼֵ��dp[0] = nums[0]
//������ ��temp����dp[i]
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