/*
@time:2020-11-24
@author:gyl
@series:sort
@problem：给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> inputnum {5,2,3,1};
//插入排序
vector<int> insert_sort(vector<int>& nums) 
{
    
   for(int j=1;j<nums.size();j++)
   {
       int key = nums[j];//key是要出入的数字
       //插入到排列好的nums[0,...,j-1]
       int i= j-1;
       while(i>=0&&nums[i]>key)
       {
           nums[i+1] = nums[i];//若前面的数大于要插入的数，则跟它调换位置
           i = i-1;
       }
       nums[i+1] = key;//由于i再循环中已经减一了，这里的插入必须加一后赋值，不然会越界
   }
    return nums;

}
int main()
{
    vector<int> sorted_num = insert_sort(inputnum);
    for(int i=0;i<sorted_num.size();i++)
    {
        cout<<sorted_num[i]<<endl;

    }
    system("pause");
    return 0;
}
