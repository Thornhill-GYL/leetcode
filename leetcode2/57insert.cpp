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
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int min = newInterval[0];
    int max = newInterval[1];
    for(int i=0;i<intervals.size();i++)
    {
        
    }



}