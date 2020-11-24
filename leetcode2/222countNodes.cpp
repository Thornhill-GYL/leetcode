/*
@time:2020-11-24
@author:gyl
@sereis:每日一题
@Problem:给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6
*/
#include <vector>
#include <queue>
#include <iostream>
#include<math.h>
using namespace std;
struct TreeNode
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  vector<int> treenum{ 1,2,3,4,5,6,NULL};
TreeNode* create(vector<int> data, int index, int n)
{
	if (index >= n || data[index] == NULL)
		return NULL;
	TreeNode* root = new TreeNode(NULL);
	root->val = data[index];
	root->left = create(data, 2 * index + 1, n);
	root->right = create(data, 2 * index + 2, n);

	return root;
}
//层次遍历的方法
  int countNodes(TreeNode* root) 
{
    TreeNode*q = root;
    queue<TreeNode*> qtree;
    qtree.push(q);
    int s =0;
 
    int ans = 0;
    while(!qtree.empty())
    {
        s=qtree.size();
        while(s>0)
        {
            if(qtree.front()->left)
            {
                qtree.push(qtree.front()->left);
                ans++;
            }
       
            

            if(qtree.front()->right)
            {
                qtree.push(qtree.front()->right);
                ans++;
            }
            
            s = s-1;
            qtree.pop();
        }
        
    }
    ans +=1;
    return ans;
}
//递归
int revecount(TreeNode* root)
{
   if(root == NULL)
   {
       return 0;
   }
    int left = revecount(root->left);
    int right = revecount(root->right);

    return left+right+1;
    
}
int main()
{
    TreeNode* root = create(treenum,0,treenum.size());
    int ans = revecount(root);
    cout<<ans<<endl;
    system("pause");
    return 0;
}