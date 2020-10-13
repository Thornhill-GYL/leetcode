/*
@time:2020-10-13
@author:gyl
@series:每日一题
@problem:给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
 struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<int> listnum {1,2,3,4};
ListNode* creat(vector<int> num,int n)
{
    ListNode* head = new ListNode(num[0]);
    ListNode* tmp =head;
    for(int i=1;i<n;i++)
    {
        tmp->next = new ListNode(num[i]);
        tmp = tmp->next;
    }
    return head;
}
void listprint(ListNode* shownode)
{
    ListNode* ptr = shownode;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<endl;
        ptr = ptr->next;
    }
}
/*
非递归：
遇事不决，先在head前面建立空的头，记录节点位置，防止节点移动而失去遍历起始点。
因为要两两对调，则需要记录 head->next,head->next->next
特别是在调换节点后需要注意将next,next进行移动

执行用时：
4 ms
内存消耗：
7.4 MB

*/
ListNode* swapPairs(ListNode* head) 
{
    ListNode* fakehead = new ListNode(0);
    fakehead->next = head;
    ListNode* tmp = fakehead;//tmp->next=head
    while(tmp->next!=nullptr&&tmp->next->next!=nullptr)
    {
        ListNode* node1 = tmp->next;
        ListNode* node2 = tmp->next->next;

        tmp->next = node2;
        node1->next = node2->next;
        node2->next= node1;
        tmp = node1;
    }
    return fakehead->next;
  

}

int main()
{
    int leng = std::end(listnum)-std::begin(listnum);
    ListNode* head = creat(listnum,leng);
    ListNode* SWPIRhead = swapPairs(head);
    listprint(SWPIRhead);
    system("pause");
    return 0;
}