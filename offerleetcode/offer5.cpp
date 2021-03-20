/*
@time:2021-03-20
@author:gyl
@serise:offer5
@problem:输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


=
128 ms	23.7 MB
利用前序遍历和中序遍历的性质，构造一个树节点的栈和一个节点的位置栈
*/


#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(NULL);
        TreeNode* tmp = new TreeNode(NULL);
        stack<int> loc;
        stack<TreeNode*> s;
        if(preorder.empty()||inorder.empty())
        {
            return NULL;
        }
        for(int i=0;i<preorder.size();i++)
        {
            for(int j=0;j<inorder.size();j++)
            {
                if(preorder[i]==inorder[j])
                {
                    if(!s.empty()&&!loc.empty())
                     {
                      if(j<loc.top())
                        {
                         tmp = s.top();
                         TreeNode* left = new TreeNode(inorder[j]);
                            tmp->left = left;
                            
                            loc.push(j);
                            s.push(left);
                        }
                     else
                     {
                         while(!loc.empty()&&!s.empty()&&j>loc.top())
                            {
                              tmp = s.top();
                               s.pop();
                             loc.pop();
                         }
                         TreeNode* right = new TreeNode(inorder[j]);
                         tmp->right = right;
                         loc.push(j);
                         s.push(right);
                        }


                 }
                 else
                 {
                      root->val = inorder[j];
                      loc.push(j);
                     s.push(root);
                 }

                }
            }
        }
        return root;

    }