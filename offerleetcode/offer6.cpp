/*
@time:2021-03-20
@author:gyl
@serise:offer6
@problem:用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]


*/
/*
372 ms	101.1 MB

考察C++类的定义
要定义两个数字栈
注意弹栈的时候的需要逻辑
*/

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

class CQueue {
public:
    stack<int> s1,s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);

    }
    
    int deleteHead() 
    {
        int delenum = 0;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int num=s1.top();
                s2.push(num);
                s1.pop();
            }
        }

        if(s2.empty())
        {
            return -1;
        }
        else
        {
            delenum = s2.top();
            s2.pop();
            return delenum;
        }
       

    }
};