/*
@time:2021-3-25
@author:gyl
@series:每日一题(中等)
@problem:Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
//不用delete 哭了
 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


*/
#include<bits/stdc++.h>
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/*不删掉重复节点*/
  ListNode* deleteDuplicates(ListNode* head) 
{
    if(head == nullptr)
    {
        return head;
    }
    ListNode* dummyhead = new ListNode(0, head);
    ListNode* cur = dummyhead;
    while(cur->next&&cur->next->next)
    {
        if(cur->next->val == cur->next->next->val)
        {
            int x = cur->next->val;
            while(cur->next&&cur->next->val == x)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
        
    }
    return dummyhead->next;
}
