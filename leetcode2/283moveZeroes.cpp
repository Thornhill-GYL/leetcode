/*
@time:2020-11-19
@author:gyl
@series:每日一题
@problem:给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inputnum {1,0,0,3,4,0};
/*
执行用时：
16 ms

内存消耗：
9.2 MB

方法：遍历数组，记录0的位置
对于第I的元素，若前面有n个0，则将nums[i-n]的位置复制为nums[i]
遍历完成后，再末尾插入0
*/
void moveZeroes(vector<int>& nums) 
{
    int count_zero = 0;
    int loc = 0;
    for(int i = 0 ;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            count_zero++;
        }
        else if(nums[i]!=0&&count_zero!=0)
        {
            loc = i-count_zero;
            nums[loc] = nums[i];
        }
    }
    for(int i=0;i<count_zero;i++)
    {
        nums[nums.size()-1-i]=0;
    }
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<endl;
    }
}
int main()
{
    moveZeroes(inputnum);
    system("pause");
    return 0;
}