/*
@time:2020-10-08
@author:gyl
@problem:(106)根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
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
vector<int> inorder {9,3,15,20,7};
vector<int> postorder {9,15,7,20,3};
void Print(TreeNode* p)
{
   if(p==NULL)
   {
       return ;
   }
   cout<<p->val<<endl;
   Print(p->left);
   Print(p->right);

}
/*
执行用时：104 ms, 在所有 C++ 提交中击败了8.32%的用户
内存消耗：17 MB, 在所有 C++ 提交中击败了79.72%的用户
此方法与前序遍历和中序遍历构建方法相同;
105\106可接合进行做
共同之处都是
借助前序遍历和后序遍历 根\左子树\右子树的特点.
*/
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
        TreeNode *root = new TreeNode(NULL);
        TreeNode *tmp = new TreeNode(NULL);
        stack<int> loc;
        stack<TreeNode*> stree;
        int postleng = std::end(postorder)-std::begin(postorder);
        int inleng = std::end(inorder)-std::begin(inorder);
        if(inorder.empty()||postorder.empty())
        {
            return NULL;
        }
        for(int i=postleng-1;i>=0;i--)
        {
            for(int j=0;j<inleng;j++)
            {
                if(postorder[i]==inorder[j])
                {
                    if(!stree.empty()||!loc.empty())
                    {
                        if(j>loc.top())//位置比栈顶位置大,则它为右节点
                        {
                            tmp = stree.top();
                            TreeNode* rightnode = new TreeNode(inorder[j]);
                            tmp->right = rightnode;
                            tmp = rightnode;
                            stree.push(tmp);
                            loc.push(j);
                        }
                        else
                        {
                            while(!stree.empty()&&!loc.empty()&&j<loc.top())
                            {
                                tmp = stree.top();
                                stree.pop();
                                loc.pop();
                            }
                            TreeNode* leftcode = new TreeNode(inorder[j]);
                            tmp->left = leftcode;
                            tmp = leftcode;
                            stree.push(tmp);
                            loc.push(j);
                          
                        }
                        
                    }
                    else
                    {
                        loc.push(j);
                        root->val=inorder[j];
                        stree.push(root);
                    }
                
                }
            }
        }
        return root;
    
}
int main()
{
    TreeNode *root = buildTree(inorder,postorder);
    Print(root);
    system("pause");
    return 0;
}