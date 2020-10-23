/*
@time:2020-10-23
@author:gyl
@series:每日一题
@problem：
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
vector<int> inputnum {1,2,3,3,1};
ListNode* creatList(vector<int> num)
{
    ListNode* head = new ListNode(num[0]);
    ListNode* tmp = head;
    for(int i=1;i<num.size();i++)
    {
        tmp->next = new ListNode(num[i]);
        tmp = tmp->next;
    }
    return head;
}
ListNode* reversenode(ListNode *head)
{
    ListNode* pre = head;
    ListNode* current = pre->next;
    ListNode* pnext = new ListNode(NULL);
    while(current)
    {
        pnext = current->next;
        current->next = pre;
        pre = current;
        current = pnext;
    }
    head->next = nullptr;
    head = pre;
    return head;
}

void Print(ListNode* head)
{
    ListNode* node = head;
    while(node)
    {
        cout<<node->val<<endl;
        node = node->next;
    }
}
/*
执行用时：
28 ms
内存消耗：
13.9 MB
简单题目 使用的是找中点，然后将后半部分逆转，然后进行比较的方法
*/
bool isPalindrome(ListNode* head) 
{
   if(!head|| !head->next)
   {
       return true;
   }
   ListNode* fastnode = head;
   ListNode* slownode = head;
    
   while(fastnode->next&&fastnode->next->next)
   {
       fastnode = fastnode->next->next;
       slownode = slownode->next;
   }
   ListNode* newhead = slownode->next;
   slownode->next = nullptr;
   Print(head);
   cout<<endl;
   
   newhead = reversenode(newhead);
   Print(newhead);
   while (newhead)
   {
       if(head->val != newhead->val)
       {
           return false;
       }
       head = head->next;
       newhead = newhead->next;
   }
   
    return true;

}
int main()
{
    ListNode* head = creatList(inputnum);
    bool ans = isPalindrome(head);
    cout<<boolalpha<<ans<<endl;
    system("pause");
    return 0;
}