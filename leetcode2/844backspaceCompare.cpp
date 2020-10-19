/*
@time:2020-10-19
@author:gyl
@series:每日一题
@problem:844给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。
示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
*/
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// vector<string> S{"ab#c"};
// vector<string> T{"ad#c"};
string S = "a##bc";
string T = "#a#c";
/*
执行用时：0 ms
内存消耗：6.6 MB

使用栈的方法：
两个字符串 ，使用两个栈存储
若遇到‘#“符号，且栈不为空，则将栈顶pop
不是#符号，则入栈

待两个字符串 全部入栈后进行比较
若在栈中比较出现不相同，直接false
若循环结束后，则判断栈是否为空，若任何一个不为空 则false
其余情况则true
*/
stack<char> deal_stack(string org_str)//该函数用于处理字符串中的”#”符号
{
    stack<char> char_s;
    for(int i = 0;i<org_str.size();i++)
    {
    
        if(org_str[i] != '#')
        {
            char_s.push(org_str[i]);
        }
        else
        {
            if(!char_s.empty())//遇到“#”符号，若栈不为空，则栈顶pop
            {
                char_s.pop();
            }
            
        }
        
    }
    return char_s;

}
bool backspaceCompare(string S, string T) //该函数用于比较两个字符串存储后的栈
{
    
    stack<char> char_S = deal_stack(S);
    stack<char> char_T = deal_stack(T);

    while(!char_S.empty()&&!char_T.empty())
    {
        cout<< "char_s"<<char_S.top()<<endl;
        cout<< "char_T"<<char_T.top()<<endl;
        if(char_S.top() != char_T.top())//比较中 若出现不同的字符 ，直接false
        {
            return false;
        }
        else
        {
            char_S.pop();
            char_T.pop();
        }
        
    }
    if(!char_S.empty()||!char_T.empty())//while之后，若栈不为空则false
    {
        return false;
    }
    //其他情况则都是true
    return true;
        
}
//双指针的情况 之后再看吧。。。

int main()
{
    bool ans = backspaceCompare(S,T);
    cout<< boolalpha<<ans <<endl;
    system("pause");
    return 0;
}