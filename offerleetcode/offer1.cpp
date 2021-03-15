/*
@time:2021-03-15
@author:gyl
@serise:offer1
@problem:找出数组中重复的数字。
push 更新

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

*/
#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
执行用时：
60 ms：
22.3 MB
*/
/*
O(n*2)会超时，所以首先使用排序函数，然后根据顺序则可以快速找到对应的结果了。
*/
int findRepeatNumber(vector<int>& nums) {
        int ans=-1;
        
        std::sort(nums.begin(),nums.end());
       int ans=-1;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
           if(nums[i]==nums[i+1])
           {
              return nums[i];
           }
        }
        return ans;
}
/*
原地置换方法
该方法使用的原因是由于，数组中存储的数字是不大于n-1的
该算法的目的是为了让0号位置对应的就是0这个数字，依次对应。
若在归位过程中，则判断是否有重复情况，意味着该数字在其他位置与原数字相同
整个过程相当于排序的过程
执行用时：
44 ms

内存消耗：
22.4 MB

*/
int findRepeatNumber_official(vector<int>& nums) 
{
    int temp = 0;
    for(int i=0;i<nums.size();i++)
    {
     while(nums[i]!=i)//判断数字是否归位
     {
         if(nums[nums[i]]==nums[i])//若在不同位置上出现相同数字 则就是答案
         {
             return nums[i];
         }
         //如果不相等，则交换位置
         temp=nums[i];//将目前的用TEMP保存
         nums[i]=nums[temp];//交换两者的位置
         nums[temp]=temp;//放入对应的位置
     }   
    }
    return -1;
}

/*
哈希表的方法
执行用时：
60 ms 
内存消耗：
26.9 MB

*/
int findRepeatNumber_hash(vector<int>& nums) 
{
    unordered_map<int,int> mp;
    for(auto& num:nums)
    {
        mp[num]++;
        if(mp[num]>1)
        {
            return num;
        }
    }
    return -1;
}