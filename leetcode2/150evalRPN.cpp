/*
@time:2021-3-20
@author:gyl
@problem:根据 逆波兰表示法，求表达式的值。(中等)

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

 

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

*/
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
/*12 ms	11.5 MB*/
/*逆波兰式：从前面读取数字，压入栈中
若遇到操作符，则将栈顶的数字和它的前一位取出做运算，然后运算结果入栈
*/
int evalRPN(vector<string>& tokens) {
        int ans = 0;
        if(tokens.size()==0)
        {
            return 0;
        }
        
        stack<int> num;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
               
                int tmp = stoi(tokens[i]);
                num.push(tmp);
                
            }
            else
            {
                if(!num.empty())
                {
                    int op2 = num.top();
                    num.pop();
                    int op1 = num.top();
                    num.pop();
                    if(tokens[i]=="+")
                    {
                        ans = op1+op2;
                       
                    }
                    else if(tokens[i]=="-")
                    {
                        ans = op1-op2;
                        
                    }
                    else if(tokens[i]=="*")
                    {
                        ans = op1*op2;
                    }
                    else if(tokens[i]=="/")
                    {
                        ans = op1/op2;
                        
                    }
                     num.push(ans);
                     
                }
               
            }
        }
        ans = num.top();
        return ans;

    }