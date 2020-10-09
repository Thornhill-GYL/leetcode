/*
@time:2020-1-=09
@author:gyl
@problem:(107)给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
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
vector<int> treenum{ 3,9,20,NULL,NULL,15,7 };
TreeNode *creat(vector<int> data,int index, int n)
{
    if(index >=n || data[index]==NULL)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(NULL);
    root->val = data[index];
    root->left = creat(data, index*2+1,n);
    root->right = creat(data,index*2+2,n);
    return root;
}
/*
此题较为简单
与树的层次遍历相同，最后将其结果反转即可
需要注意的是 树的层次遍历的写法和二维数组的使用方法
*/
vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int>> ans{};
    vector<int> tmp;//树每一层的节点。
    if(root == NULL)
    {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    int size = 0;
    while(!q.empty())
    {
        size = q.size();
        while(size>0)
        {
            tmp.push_back(q.front()->val);
            if(q.front()->left)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            size=size-1;
            q.pop();
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int leng = std::end(treenum)-std::begin(treenum);
    TreeNode* root = creat(treenum,0,leng);
    vector<vector<int>> havetry{};
    havetry = levelOrderBottom(root);
    vector<vector<int>> overans{};
    reverse(havetry.begin(),havetry.end());
    for (vector<vector<int>>::iterator it = havetry.begin(); it != havetry.end(); ++it)
	{
		for (int i = 0; i < (*it).size(); ++i)
			cout << (*it)[i] << " " ;
		cout << endl;
	}



    system("pause"); 
    return 0;

}