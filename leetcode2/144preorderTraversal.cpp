/*
@time:2020-10-27
@author:gyl
@series:每日一题
@problem:给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  /*
  执行用时：0 ms
内存消耗：8.5 MB
前序遍历，使用栈
  */
vector<int> preorderTraversal(TreeNode* root) 
{
    vector<int> ans {};
    if(root==nullptr)
    {
        return ans;
    }
    stack<TreeNode*> s;
    TreeNode* ptr = root;
    while(ptr!=nullptr||!s.empty())
    {
        while(ptr)
        {
            ans.push_back(ptr->val);
            s.push(ptr);
            ptr = ptr->left;
        }
        if(!s.empty())
        {
            ptr = s.top()->right;
            s.pop();
        }
    }

    return ans;
        
}