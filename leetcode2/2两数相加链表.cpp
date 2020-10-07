/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include <iostream>
#include <string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
int main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *l11 = new ListNode(4);
	ListNode *l12 = new ListNode(3);
	l1->next = l11;
	l11->next = l12;

	ListNode *l2 = new ListNode(5);
	ListNode *l21 = new ListNode(6);
	ListNode *l22 = new ListNode(6);
	l2->next = l21;
	l21->next = l22;

	ListNode *p = l1;
	ListNode *q = l2;
	ListNode *finalsum = new ListNode(-1);
	ListNode *tmp = finalsum;
	int tempsum = 0;
	int carry = 0;
	while (p != NULL || q != NULL)
	{
		tempsum = carry;
		if (p != NULL)
		{
			tempsum += p->val;
			p = p->next;
		}
		else
		{
			tempsum += 0;
		}
		if (q != NULL)
		{
			tempsum += q->val;
			q = q->next;
		}
		else
		{
			tempsum += 0;
		}
		if (tempsum >= 10)
		{
			tmp->next = new ListNode(tempsum - 10);

		}
		else
		{
			tmp->next = new ListNode(tempsum);
		}
		tmp = tmp->next;
		carry = tempsum/10;
		
		
	}
	if (carry == 1)
	{
		tmp->next = new ListNode(1);
		tmp = tmp->next;
	}
	while (finalsum->next != NULL)
	{
		std::cout << finalsum->next->val << endl;
		finalsum->next = finalsum->next->next;
	}
	system("pause");
	return 0;
}
