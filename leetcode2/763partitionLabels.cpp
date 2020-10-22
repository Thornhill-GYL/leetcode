/*
@time:2020-10-22
@author:gyl
@series:每日一题
@proble:763字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
string S = "ababcbacadefegdehijhklij";
vector<int> partitionLabels(string S)
 {
     
     vector<int> number{};
     int i=0;
    
     while(i<S.size())
     {
         for(int j = S.size()-1;j>0;j--)
         {
             if(S[i]==S[j])
             {
                 number.push_back(j);
                 break;
             }
         }
        
         i++;
     }
     return number;
 }
int main()
{
    vector<int> show = partitionLabels(S);
    return 0;
}