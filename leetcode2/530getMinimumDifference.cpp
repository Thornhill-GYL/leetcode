/*
@time:2020-10-12
@author:gyl
@problem:给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 

提示：

树中至少有 2 个节点。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
递归的方法：
受到启发，中序遍历刚好可以从左边到中间再到右边
只需要计算当前的和之前的节点的插值
*/
int min_num = INT_MAX;
TreeNode* pre;//这个地方的不能初始化，不然程序默认它是零，得到错误的结果
void inorder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//中序遍历，将左子树存入
	inorder(root->left);
	if (pre != NULL)
	{
		min_num = min(min_num, abs(root->val - pre->val));
	}
	pre = root;//记录当前节点
	//右节点存入
	inorder(root->right);
}
/*
非递归方法需要补充
以及建立二叉搜索树的code也需要补充
*/
//官方函数
int getMinimumDifference(TreeNode* root) {
	inorder(root);
	return min_num;
}
