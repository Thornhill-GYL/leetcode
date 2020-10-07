/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空
*/
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
void wrongnumber(vector<int> &num1, vector<int> &num2, vector<int> &finnum)
{
	num1.push_back(1);
	num1.push_back(7);
	num1.push_back(8);
	num1.push_back(10);

	num2.push_back(5);
	num2.push_back(8);
	num2.push_back(9);

	float mid_number = 0.0;
	int length = 0;
	int middle = 0;
	if (num2.size() == 0)
	{
		length = num1.size();
		middle = length / 2;
		if (length % 2 == 0)
		{
			mid_number = float((num1[middle] + num1[middle - 1])) / 2;
		}
		else
			mid_number = num1[middle];
	}
	else if (num1.size() == 0)
	{
		length = num2.size();
		middle = length / 2;
		if (length % 2 == 0)
		{
			mid_number = float((num2[middle] + num2[middle - 1])) / 2;
		}
		else
			mid_number = num2[middle];

	}
	else
	{
		int j = 0;
		int i = 0;
		vector<int> bigvec;
		vector<int> smallvec;
		if (num2.size() >= num1.size())
		{
			bigvec = num2;
			smallvec = num1;
		}
		else
		{
			bigvec = num1;
			smallvec = num2;
		}

		while (j < bigvec.size())
		{
			while (i < smallvec.size())
			{
				if (bigvec[j] > smallvec[i])
				{
					finnum.push_back(smallvec[i]);
					i++;
				}
				else if (bigvec[j] < smallvec[i])
				{
					finnum.push_back(bigvec[j]);
					j++;
					break;
				}
				else
				{
					finnum.push_back(smallvec[i]);
					i++;
					j++;
					break;
				}

			}
			if (i >= smallvec.size())
			{
				finnum.push_back(bigvec[j]);
				j++;
			}


		}
		length = finnum.size();
		middle = length / 2;
		if (length % 2 == 0)
		{
			mid_number = float((finnum[middle] + finnum[middle - 1])) / 2;
		}
		else
			mid_number = finnum[middle];

	}
}
double middle(vector<int>& num)
{
	int length = num.size();
	int k = (length + 1) / 2;
	if (length % 2 == 1)
	{
		return num[k - 1];
	}
	else
	{
		return (num[k] + num[k - 1]) / 2.0;
	}
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() == 0)
		return middle(nums1);
	if (nums2.size() == 0)
		return middle(nums2);
	if (nums1.size() > nums2.size())
	{
		return findMedianSortedArrays(nums2, nums1);
	}
	int m = nums1.size();
	int n = nums2.size();
	int left_find = 0;
	int final_left_one = 0;
	int first_right = 0;
	int right_find = m;
	int k = (m + n + 1) / 2;//两个数组的一起的中位数。
	//开始寻找两个数组左边都小于右边的情况。
	while (left_find < right_find)
	{
		final_left_one = (left_find + right_find) / 2;//final_left是小数组右边的第一个
		first_right = k - final_left_one;//first_right是大数组右边的第一个；
		if(first_right<=0)
			break;
		if (nums1[final_left_one] < nums2[first_right - 1])
		{
			left_find = final_left_one + 1;

		}
		else
		{
			right_find = final_left_one;
		}
		
	}
	final_left_one = left_find;
	first_right = k - left_find;
	int leftmax = max(nums1[final_left_one - 1], nums2[first_right - 1]);
	int rightmin = min(nums1[final_left_one], nums2[first_right]);
	if ((nums1.size() + nums2.size()) % 2 == 1)
	{
		return leftmax;
	}
	else
	{
		return (leftmax + rightmin) / 2.0;
	}
}
int main()
{
	vector<int> num1;
	vector<int> num2;
	vector<int> finnum;
	num1.push_back(1);
	num1.push_back(7);
	num1.push_back(8);
	num1.push_back(10);

	num2.push_back(5);
	num2.push_back(8);
	num2.push_back(9);
	double result = findMedianSortedArrays(num1, num2);
	std::cout << result << endl;
	system("pause");
	return 0;


	

}