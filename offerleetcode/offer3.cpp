/*
@time:2021-03-16
@author:gyl
@serise:offer3
@problem:请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."


*/
#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
自己解法，首先在S中找到空格，将位置加到数字中，然后根据数据公式在指定位置加入%20；
然后将S中的空格去掉。
	4 ms	6.2 MB
*/
string replaceSpace(string s)
{
    vector<int> rem;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            rem.push_back(i);
        }
    }
    for(int i=0;i<rem.size();i++)
    {
        s.insert(rem[i]+3*i,"%20");
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            s.erase(i,1);
        }
    }
    return s; 
}
/*
参考别人的解法：利用C++的特性，再创建一个string 得到结果
0 ms	6.1 MB
*/
string replaceSpace_official(string s) 
{
    string ans="";
    for(char& ch:s)
    {
        if(ch ==' ')
        {
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        }
        else
        {
            ans.push_back(ch);
        }
        
    }
    return ans;
}