/*
@time:2020-11-30
@author:gyl
@series:每日一题
@problem:给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例 1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
string inputstr = "vvvio";
/*忽略了最多的次数可能不是最前面开始的
但是对字符串相同的数进行了正确处理*/
string fail_reorganizeString(string S) 
{
    vector<int> nums(26);
    string ans = "";
    int look_aft=0;
    for(char ch:inputstr)
    {
        ++nums[ch-'a'];

    }
    sort(nums.begin(),nums.end());
    while(ans.length()!=inputstr.length())
    {
        for(int i=0;i<26;i++)
    {
         look_aft=0;
        if(nums[i]!=0 )
        {
            if((i+'a'!=ans[ans.length()-1]))
            {
                ans.push_back(i+'a');
                nums[i]--;
                i=0;
                break;
            }
            else
            {
                for(int j=i+1;j<26;j++)
                {
                    if(nums[j]!=0)
                    {
                       i=j-1;
                       look_aft=1;
                       break;
                    }
                }
                if(look_aft==0)
                {
                    return "";
                }
                
              
            }
            
            
            
        }
    }
    }
    return ans;
}
/*
该解法与我自己写的大概相同，但是我失败在于没有将字符串的信息加入到排序中
执行用时：
0 ms
内存消耗：
6.5 MB
,
*/
string reorganizeString(string S) {
        int n = S.size();
        vector<int> count(26, 0);
        for (auto c : S) {
            count[c - 'a'] += 100; // 统计次数
            if (count[c - 'a'] / 100 > (n + 1) / 2) return ""; // 超过（n+1)/2个字符，不可能得到答案
        }
        for (int i = 0; i < 26; ++i) count[i] += i; // 将字符信息加入数组值中,
        // 此时count中的元素存储了次数和字符信息
        // 如 count[i] = 203 表示字符 'd'='a'+203%100 出现了 2=203/100 次
        sort(count.begin(), count.end()); // 对次数从小到大排序
        int index = 1;
        string ret(n, ' ');
        for (auto c : count) {
            int cnt = c / 100; // 取出次数
            char ch = 'a' + (c % 100); // 取出字符信息
            for (int i = 0; i < cnt; ++i) {
                if (index >= n) index = 0; // 第一遍走完 从0开始
                ret[index] = ch;
                index += 2; // 间隔添加相同字符
            }
        }
        return ret;
    }
int main()
{
    string final = reorganizeString(inputstr);
    cout<<final<<endl;
    system("pause");
    return 0;
}
