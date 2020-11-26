/*
@time:2020-11-26
@author:gyl
@serise:每日一题
@problem:给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。

*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> inputnum {5,3,9,4,5,7};
/*
执行用时：
12 ms

内存消耗：
8.8 MB

这道题重点考察的还是排序，这里偷懒了，直接用的是C++内置的sort的排序，但是其效果还是很好的
这道题是假的困难
*/
 int maximumGap(vector<int>& nums) 
{
    int ans =0;
    
    if(nums.size()<=1)
    {
        return 0;
    }
    sort(nums.begin(),nums.end());
    int tmp= 0;
    int max = INT_MIN;
    for(int i=0;i<nums.size()-1;i++)
    {
        tmp=nums[i+1]-nums[i];
        if(tmp>max)
        {
            max = tmp;
        }
    }
    ans = max;
    return ans;

}
int main()
{
    int ans = maximumGap(inputnum);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
