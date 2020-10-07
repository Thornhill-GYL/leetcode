//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
//
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int treenum[]{ 1,2,2,3,3,NULL,NULL,4,4 };
//�����Ĺ���
TreeNode *create(int data[], int index, int n)
{
	TreeNode *root = new TreeNode(NULL);
	if (index >= n || data[index] == NULL)
		return NULL;
	root->val = data[index];
	root->left = create(data, 2 * index + 1, n);
	root->right = create(data, 2 * index + 2, n);

	return root;
}
/*
�÷������Ե����ϲ�ѯ�Ƿ�ƽ�������
�������������ߵĽڵ㿪ʼ�ж�
�����ж����������Ƿ�߶Ȳ����1���������1ֱ�ӷ���-1
��ƽ�⣬����������������ߵĲ�����
*/
//int maxDepth(TreeNode* root)
//{
//	
//	if (root == NULL)
//		return 0;
//	int left = maxDepth(root->left);
//	int right = maxDepth(root->right);
//	if (left == -1 || right == -1 || abs(left - right) > 1)
//		return -1;
//	else
//		return  max(left, right) + 1;
//
//}
//bool isBalanced(TreeNode* root)
//{
//	int ans = maxDepth(root);
//	if (ans == -1)
//		return false;
//	else
//		return true;
//
//}
/*
�Զ����µ����
�ж�ÿ���ڵ�����������Ƿ�ƽ��
*/
int maxDepth(TreeNode* root)
{
	int ans = 0;
	if (root == NULL)
		return 0;
	int left = maxDepth(root->left) + 1;
	int right = maxDepth(root->right) + 1;
	ans = left > right ? left : right;
	return ans;
}
bool isBalanced(TreeNode* root)
{
	if (root == NULL)
		return true;
	if ((abs(maxDepth(root->left) - maxDepth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right))
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int length = std::end(treenum) - std::begin(treenum);
	TreeNode *root = create(treenum, 0, length);
	bool ans = isBalanced(root);
	std::cout << boolalpha<<ans << endl;
	system("pause");
	return 0;
}