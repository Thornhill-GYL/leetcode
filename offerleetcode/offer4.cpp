/*
@time:2021-03-17
@author:gyl
@serise:offer4
@problem:输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

/*采取反转链表的方法
4 ms	8.3 MB
*/
 vector<int> reversePrint(ListNode* head) 
 {
     if(head==NULL)
     {
         return {};
     }
     vector<int> ans{};
     ListNode* pre = head;
     ListNode* current  = head->next;
     while(current!=NULL)
     {
         ListNode* pnext = current->next;
         current->next = pre;
         pre = current;
         current = pnext;
     }
     head->next=NULL;//这个地方要把最开始的HEAD->next=NULL作为条件
     head=pre;
     while(head!=NULL)
     {
         ans.push_back(head->val);
         head=head->next;
     }
     return ans;
}
/*采用栈的方法
8 ms	8.7 MB*/
vector<int> reversePrint_stack(ListNode* head) 
{
    stack<int> pre_ans;
    vector<int> ans{};
    while(head!=NULL)
    {
        pre_ans.push(head->val);
        head = head->next;
    }
    while(!pre_ans.empty())
    {
        ans.push_back(pre_ans.top());
        pre_ans.pop();
    }
    return ans;
}