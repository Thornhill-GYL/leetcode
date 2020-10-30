/*
@time:2020-10-29
@author:gyl
@series:每日一题
@problem:129给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/*
使用深度优先搜索
执行用时：
4 ms
内存消耗：
12.5 MB
这道题的重点是，每次计算都带着前面的数值了

*/
int getsum(TreeNode* root, int prenum)
{
    if(root == nullptr)
    {
        return 0;
    }

    int sum = prenum*10 + root->val;//每次进来计算当前的和；
    if(root->left==nullptr&&root->right==nullptr)
    {
        return sum;//如果是叶子节点，则返回目前的sum
    }
    else//若不是叶子节点
    {
        return getsum(root->left,sum)+getsum(root->right,sum);//返回左右递归的和
    }
    
}
int sumNumbers(TreeNode* root) 
{
    int ans = getsum(root,0);
}
/*
之后补一个广度优先搜索的算法
用一个队列记录树节点，一个队列记录树的节点值
如果当前是叶子节点则将它的值加入sum
如果左右还有子节点，则将之前的节点的数值*10再加入当前节点值
相当于每询问一次都是在创建一个完整的数字
执行用时：
4 ms
内存消耗：
13 MB
*/
int usetwoqueue(TreeNode* root)
{
    queue<TreeNode*> qnode;
    queue<int> qval;
    qnode.push(root);
    qval.push(root->val);
    int sum = 0;
    while(!qnode.empty())
    {
        TreeNode* tmp = qnode.front();
        int num = qval.front();
        qnode.pop();
        qval.pop();

        TreeNode* left= tmp->left;
        TreeNode* right = tmp->right;
        if(left==nullptr&&right==nullptr)
        {
            sum+=num;
        }
         else
         {
             if(left!=nullptr)
             {
                 qnode.push(left);
                 qval.push(num*10+left->val);
             }
             if(right!=nullptr)
             {
                 qnode.push(right);
                 qval.push(num*10+right->val);
             }
         }
         
    }
    return sum;
}