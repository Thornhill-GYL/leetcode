/*
@time:2020-10-20
@author:gyl
@series:每日一题
@problem:给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<int> inputnum{1,2,3,4,5};
ListNode* creatlist(vector<int> num)
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
void PrintList(ListNode* head)
{
    while(head!=nullptr)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
}
ListNode* reverselist(ListNode* head)
{
    ListNode* pre = head;
    ListNode* current = pre->next;
    ListNode* pnext =new ListNode(NULL);

    while(current!=nullptr)
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
/*
执行用时：
68 ms6
内存消耗：
18.9 MB
由于链表无法的随意操控具体的位置
则粗暴的将链表存到vector中进行操作
 */
void reorderList(ListNode* head) 
{
    if(head == nullptr)
    {
        return;
    }
    vector<ListNode*> middlevec;
    ListNode* node = head;
    while(node!=nullptr)
    {
        middlevec.emplace_back(node);
        node = node->next;
    }
    int i= 0;
    int j = middlevec.size()-1;
    while(i<j)
    {
        middlevec[i]->next = middlevec[j];
        i++;
        if(i == j)//会出现 i++后，i与j相等的情况，则需要提前突出
        {
            break;
        }
        middlevec[j]->next = middlevec[i];
        j--;
    }
    middlevec[i]->next = nullptr;//循环结束后，i对应的元素为最后的元素。

}
/*
递归的方法
执行用时：
68 ms6
内存消耗：
18MB
大致的想法：每次处理链表 得到链尾
           将处理的头部的next直接指向链尾，链尾再只向中间部分
*/
ListNode *reorderhelper(ListNode *head,int len)
{
    if(len==1)//若现在的链表只有一个节点，直接返回
    {
        ListNode* outtail = head->next;
        head->next = nullptr;
        return outtail;
    }
    if(len==2)//如果链表还有两个节点，返回的是head->next->next
    {
        ListNode* outtail = head->next->next;
        head->next->next = nullptr;
        return outtail;
    }
    //head->next,是从第二个节点，然后len-2代表的是出去head和真正的outtail的长度
    //该部分的作用就是获取中间部分的最后节点
    //得到的节点将作为head->next
    ListNode* tail = reorderhelper(head->next,len-2);
    ListNode* subhd = head->next;//subhd是中间部分的头节点
    head->next = tail;
    ListNode* outtail = tail->next;//这里的outtails是返回的tail的next
    tail->next = subhd;
    return outtail;

}
void reorderlist_2(ListNode* head)
{
    if (!head || !head->next || !head->next->next ) return;
        int len = 0;
        ListNode* h = head;
        // 求出节点数
        while (h) {
            len++;
            h = h->next;
        }
        reorderhelper(head, len);
}
int main()
{
    ListNode* head = creatlist(inputnum);
    PrintList(head);
    reorderlist_2(head);
    cout<<"reorder"<<endl;
    PrintList(head);
    system("pause");
    return 0;

}