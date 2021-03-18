/*
@time:2021-3-18
@author:gyl
@series:每日一题(中等)
@problem:给你单链表的头节点 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
反转部分链表，分为两种情况，一种是包含head 一种是不包含head 在返回时注意即可
这里的dummyhead的作用是仅仅时为了逻辑清晰，不用分情况讨论
核心思想就是，把left前一个的节点保存，然后使用反转链表的想法同样的做
*/
ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        int count=0;
        ListNode* old;
        ListNode* pre;
        ListNode* current;
        ListNode* fni;
        while(dummyhead!=nullptr)
        {
            if(left==count+1)
            {
                old = dummyhead;
                pre = old->next;
                current = pre->next;
            }
            if(right==count)
            {
                fni = dummyhead->next;
            }
            dummyhead=dummyhead->next;
            count++;

        }
        pre->next = fni;
        while(current!=fni)
        {
            ListNode* pnext = current->next;
            current->next = pre;
            pre = current;
            current = pnext;
        }
        old->next = pre;
        if(left==1)
        {
            return pre;
        }
        else
        {
            return head;
        }
        
    }
        
