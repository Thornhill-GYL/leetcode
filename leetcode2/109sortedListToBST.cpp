/*
@time: 2020-10-19 ---
@author:gyl
@problem:109
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

	  0
	 / \
   -3   9
   /   /
 -10  5
 有待解决 
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inputnum{ -10, -3, 0, 5, 9 };
ListNode *creatlist(vector<int> num)
{
	ListNode *node = new ListNode(num[0]);
	ListNode *tmp = node;
	for (int i = 1; i < num.size(); i++)
	{
		tmp->next = new ListNode(num[i]);
		tmp = tmp->next;
	}
	return node;
}
void Print_list(ListNode *node)
{
	while (node != nullptr)
	{
		cout << node->val << endl;
		node = node->next;
	}
}
int lengoflist(ListNode* head)
{
	int length = 0;
	while (head != nullptr)
	{
		length += 1;
		head = head->next;
	}
	return length;
}
TreeNode* middleroot(ListNode*& head, int left, int right)
{
	if (left >=right)
		return NULL;
	int middle = (left + (right - 1)) / 2;
	TreeNode* root = new TreeNode(NULL);
	root->left = middleroot(head, left, middle);
	root->val = head->val;
	head = head->next;
	root->right = middleroot(head, middle + 1, right);
	return root;
}
TreeNode* sortedListToBST(ListNode* head)
{
	return middleroot(head, 0, lengoflist(head));
}
int main()
{
	ListNode *node = creatlist(inputnum);
	int length = lengoflist(node);
	/*Print_list(node);*/
	cout << length << endl;
	system("pause");
	return 0;
}