/*
@time:2020-10-21
@author:gyl
@series:每日一题
@problem:
示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
示例 3：

输入：name = "leelee", typed = "lleeelee"
输出：true
示例 4：

输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。
*/
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
执行用时：
0 ms
内存消耗：
6.6 MB

双指针的做法
typed 必须比 name 长，
所以益typed作为循环

若name和typed 存在相同，则将其位置进行同步++
然后若不匹配，则查看typed 当前字符和它的前置位是否相同
相同则++，反之就false

最后循环结束 查看i是否走到name的末尾，未走到末尾则返回false;
*/
bool isLongPressedName(string name, string typed) 
{
    int i=0;
    int j = 0;
    while(j<typed.size())
    {
        if(i<name.size()&&name[i]==typed[j])
        {
            i++;
            j++;
        }
        else if(j>0&&typed[j]==typed[j-1])
        {
            j++;
        }
        else
        {
            return false;
        }
        
    }
    if(i!=name.size())
    {
        return false;
    }
    return true;
}
int main()
{
    string inputname = "alex";
    string inputtype = "aaleex";
    bool ans = isLongPressedName(inputname,inputtype);
    cout<<boolalpha<<ans<<endl;
    system("pause");
    return 0;
}