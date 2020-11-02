/*
@time:2020-11-02
@author:gyl
@series:每日一题
@problem:给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> num1 {4,9,5};
vector<int> num2 {9,4,9,8,4};
int exit_flag(vector<int> &ans,int num)
{
    for(int i=0;i<ans.size();i++)
    {
        if(num == ans[i])
        {
            return 1;
        }
    }
    return 0;

}
/*
执行用时：
28 ms
的用户
内存消耗：
10.3 MB
方法：只需要在查询的时候，看看ans数组中是否已经存在该数了

*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans {};
    int only_Flag = 0;
    for(int i=0;i<nums1.size();i++)
    {
        only_Flag = exit_flag(ans,nums1[i]);
        for(int j=0;j<nums2.size();j++)
        {
            if(nums1[i]==nums2[j]&&only_Flag==0)
            {
                ans.push_back(nums1[i]);
                // only_Flag =1;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> ans = intersection(num1,num2);
    for(int i=0;i<ans.size();i++)
    {
        cout<< ans[i]<<endl;
    }
    system("pause");
    return 0;
}