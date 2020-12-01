/*
@time:2020-12-01
@author:gyl
@series:每日一题
@problem:给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> inputnum {1,1,1,1,1,1};
/*执行用时：
20 ms
内存消耗：
13.7 MB
O(n)
注意题目的意思是找到起始和结尾的位置，不是在哪的位置
*/
vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> ans{-1,-1};
    int count=0;
    int remeberi=0;
    if(nums.size()==0)
    {
       
        return ans;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(target == nums[i])
        {
            if(count==0)
            {
                 ans[0]=i;
            }
            count++;    
            remeberi = i;        
        }
    }
   if(count!=0)
   {
       ans[1] = remeberi;
   }
   else
   {
       ans[1] = ans[0];
   }
   
    return ans;
}
int binarySearch(vector<int>& nums, int target, bool lower)
 {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
    }
int main()
{
     vector<int> ans = searchRange(inputnum,1);
     for(int num : ans)
     {
         cout<<num<<endl;
     }
     system("pause");
     return 0;
}