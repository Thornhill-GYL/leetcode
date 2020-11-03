/*
@time:2020-11-03
@author:gyl
@series:每日一题
@problem:941给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inputnum = {0,3,2,1};
/*执行用时：
52 ms
内存消耗：
21.1 MB
方法：找到最大的值的位置，然后从它的左边和右边进行查找
一定要注意数组为空的情况，这部分要单独处理
不要每次都忘记了
*/
bool validMountainArray(vector<int>& A)
{
    if(A.size()==0)
    {
        return false;
    }
    int max_loc = 0;
    int max_num = 0;
    max_num = A[0];
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>max_num)
        {
            max_num = A[i];
            max_loc = i;
        }

    }
    if(max_loc==0||max_loc==A.size()-1)
    {
        return false;
    }
    for(int i = max_loc;i>0;i--)
    {
        if(A[i]<=A[i-1])
        {
            return false;
        }
    }
    for(int i = max_loc;i<A.size()-1;i++)
    {
        if(A[i+1]>=A[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    bool ans = validMountainArray(inputnum);
    cout<<boolalpha<<ans<<endl;
    system("pause");
    return 0;
}