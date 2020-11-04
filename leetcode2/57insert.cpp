/*
@time:2020-11-04
@author:gyl
@series:每日一题
@problem:给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> inputori_num = {{1,3},{6,9}};
vector<int> test_num {2,5};
/*
6 ms	17.3 MB
方法：先找到左右两个边界的位置
然后根据左右边界，进行不同情况的操作
*/
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
	int min = newInterval[0];
	int max = newInterval[1];
	int combine_low = 0;
	int combine_high = 0;
	vector<int> new_input{};
	int leng = intervals.size();
	if (leng == 0)
	{
		intervals.push_back(newInterval);
		return intervals;
	}
	for (int i = 0; i < intervals.size(); i++)
	{
		if (min < intervals[i][0])
		{
			combine_low = i;
			new_input.push_back(min);
			break;
		}
		else if (min >= intervals[i][0] && min <= intervals[i][1])
		{
			combine_low = i;
			new_input.push_back(intervals[i][0]);
			break;
		}
		else if (min > intervals[i][0] && i == (leng - 1))
		{
			combine_low = i;
			new_input.push_back(min);
			break;
		}
	}
	for (int i = 0; i < intervals.size(); i++)
	{

		if (max < intervals[i][0])
		{
			combine_high = i;
			new_input.push_back(max);
			break;
		}
		else if (max >= intervals[i][0] && max <= intervals[i][1])
		{
			combine_high = i;
			new_input.push_back(intervals[i][1]);
			break;
		}
		else if (i == (leng - 1) && max > intervals[i][1])
		{
			combine_high = i;
			new_input.push_back(max);
			break;
		}
	}

	if (combine_high == combine_low)
	{
		if (min < intervals[combine_low][0] && max < intervals[combine_high][0])
		{
			intervals.insert(intervals.begin() + combine_high, new_input);
		}
		else if (min > intervals[combine_high][1])
		{
			intervals.push_back(new_input);
		}
		else
		{
			intervals[combine_low][0] = new_input[0];
			intervals[combine_high][1] = new_input[1];
		}

	}
	else
	{
		if (max < intervals[combine_high][0])
		{
			intervals.erase(intervals.begin() + combine_low, intervals.begin() + combine_high);
		}
		else
		{
			intervals.erase(intervals.begin() + combine_low, intervals.begin() + combine_high + 1);
		}

		intervals.insert(intervals.begin() + combine_low, new_input);
	}

	return intervals;
}



