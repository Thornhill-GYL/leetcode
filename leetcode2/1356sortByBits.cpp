/*
@time:2020-11-06
@author:gyl
@serise：每日一题
@problem:
给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。

如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。

请你返回排序后的数组。
示例 1：

输入：arr = [0,1,2,3,4,5,6,7,8]
输出：[0,1,2,4,8,3,5,6,7]
解释：[0] 是唯一一个有 0 个 1 的数。
[1,2,4,8] 都有 1 个 1 。
[3,5,6] 有 2 个 1 。
[7] 有 3 个 1 。
按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
示例 2：

输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
输出：[1,2,4,8,16,32,64,128,256,512,1024]
解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> inputnum {1024,512,256,128,64,32,16,8,4,2,1};
/*
执行用时：
476 ms
内存消耗：
10.2 MB
方法：首先计算每个数转换为二进制的1，然后根据此数据进行排序

PS:第一次出现错误是忽略了，如果二进制的1相同之后，他们本身数值的比较被忽略了

*/
int count_one(int num)
{
    int num_resul = num/2;
    int num_bina = num%2;
    int count_bina = 0;

    if(num_resul==0)
    {
        return 1;
    }
    while(num_resul!=0)
    {
        if(num_bina==1)
        {
            count_bina++;
        }
        
        num = num_resul;
        num_bina = num%2;
        num_resul = num/2;

        
    }
    return count_bina+1;
}
vector<int> sortByBits(vector<int>& arr) 
{
    if(arr.empty())
    {
        return arr;
    }
   for(int i=0;i<arr.size()-1;i++)
   {
       for(int j=0;j<arr.size()-1-i;j++)
       {
           if(count_one(arr[j])>count_one(arr[j+1]))
           {
               swap(arr[j],arr[j+1]);
           }
           else if(count_one(arr[j]) == count_one(arr[j+1])&&(arr[j]>arr[j+1]))
           {
               swap(arr[j],arr[j+1]);
           }

       }
   }
    return arr;
}

int main()
{
    vector<int> ans = sortByBits(inputnum);
    for(int i=0;i<ans.size();i++)
    {
        cout<< ans[i]<<endl;
    }
    system("pause");
    return 0;
}