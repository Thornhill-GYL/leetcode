/*
@time:2020-10-28
@author:gyl
@series:每日一题
@problem: 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

 

示例 1：

输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：

输入：arr = [1,2]
输出：false
*/
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<int> inputnum{};
/*
执行用时：
40 ms
内存消耗：
8.2 MB
这道题过于简单
首先遍历数组，将每个数出现得次数存到一个新的数组中
然后遍历新的存放着次数得数组，如果，次数相同，在数组中得位置不同，并且原来在arr中得数字也不同
那么直接return false
其他情况则都是true
*/
bool uniqueOccurrences(vector<int>& arr)
{
    // if(arr.empty())
    // {
    //     return true;
    // }
    vector<int> middle_ans{};
    int count =0;
    for(int i = 0;i<arr.size();i++)
    {
        count=0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        middle_ans.push_back(count);

    }

    for(int i=0;i<middle_ans.size();i++)
    {
        cout<<middle_ans[i]<<endl;
    }
    for(int i =0;i<middle_ans.size();i++)
    {
        for(int j = 0;j<middle_ans.size();j++)
        {
            if(i!=j&&middle_ans[i]==middle_ans[j]&&arr[i]!=arr[j])
            {
                return false;
            }

        }
    }
    return true;
}
int main()
{
    bool ans = uniqueOccurrences(inputnum);
    cout<<boolalpha<<ans<<endl;
    system("pause");
    return 0;
}