//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
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
//建树的过程
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
该方法是自底向上查询是否平衡二叉树
从最下面的最左边的节点开始判断
首先判断左右子树是否高度差大于1，如果大于1直接返回-1
若平衡，返回左右子树的最高的层数。
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
自顶向下的求解
判断每个节点的左右子树是否平衡
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