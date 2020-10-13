/*
@time:2020-10-13
@author:gyl
@problem:108将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
vector<int> treenum {-10,-3,0,5,9};
void Print(TreeNode* p)
{
	if (p == NULL)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}
/*执行用时：40 ms
内存消耗：29.3 MB
自己写的方法:
利用的是递归的思想，和分治法
有序数组，每次从中间截断，中间的那个节点作为root
截断左边的数组的中间作为左节点，右边数组中间作为右节点
然后递归就完成了
*/
TreeNode* sortedArrayToBST(vector<int>& nums)
{
    TreeNode* root = new TreeNode(NULL);
    int leng = std::end(nums)-std::begin(nums);
    if(leng==0)
    {
        return NULL;
    }
    root->val = nums[leng/2];
    std::vector<int>::const_iterator left = nums.begin();
    std::vector<int>::const_iterator middle_left  = nums.begin()+(leng/2);
    std::vector<int>::const_iterator middle_right  = nums.end()-(leng/2);
    if(leng%2==0)
    {
        middle_right = middle_right+1;
    }
    std::vector<int>::const_iterator right = nums.end();
    std::vector<int> left_num(left,middle_left);
    std::vector<int> right_num(middle_right,right);
    root->left = sortedArrayToBST(left_num);
    root->right = sortedArrayToBST(right_num);

    return root;


}
int main()
{
    TreeNode* root = sortedArrayToBST(treenum);
    Print(root);
    system("pause");
    return 0;
}