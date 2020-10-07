/*@time:2020-09-02
@author:gyl
@problem:(105)根据一棵树的前序遍历与中序遍历构造二叉树。
注意: 你可以假设树中没有重复的元素。
*/
#include<iostream>
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
vector<int> pre { };
vector<int> in { };
void Print(TreeNode* p)
{
	if (p == NULL)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}
/*
使用两个栈来解决该问题（自己想的）
与官方的第二种方法相同

栈s：保存每次复制的节点
栈loc：保存每次相等的位置
首先找到root的位置，并将它入栈（两个）
从前序开始遍历，找到与中序中相同的节点
将它的位置与当前位置栈的top比较
小：左节点
大：一直找到比该位置更大的节点的位置
	然后该节点是前一个的右节点。
执行用时：332 ms 在所有 C++ 提交中击败了 5.05%的用户
内存消耗：17.4 MB, 在所有 C++ 提交中击败了72.24%的用户
*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode* root = new TreeNode(NULL);
	TreeNode* tmp = new TreeNode(NULL);
	int lr = 0;
	stack<TreeNode*> s;
	stack<int> loc;
	if (preorder.empty() || inorder.empty())
		return NULL;
	for (int i = 0; i < std::end(preorder) - std::begin(preorder); i++)
	{
		for (int j = 0; j < std::end(inorder) - std::begin(inorder); j++)
		{
			if (preorder[i] == inorder[j])
			{
				if (!loc.empty()||!s.empty())
				{
					if (j < loc.top())//若相同时，中序位置小于当前栈顶的位置，则它是该节点的左节点
					{
						tmp = s.top();
						TreeNode* left = new TreeNode(inorder[j]);
						tmp->left = left;
						tmp = left;
						loc.push(j);
						s.push(tmp);
						
					}
					else
					{
	
						while (!loc.empty()&&j > loc.top()&&!s.empty())//若大于栈顶位置，并且当前栈不为空（防止出现在root节点之后失控的情况）
						{
							tmp = s.top();//记录pop前的栈顶，该节点为之后创建的祖先
							loc.pop();
							s.pop();
						}
						TreeNode* right = new TreeNode(inorder[j]);
						tmp->right = right;
						tmp = right;
						loc.push(j);
						s.push(tmp);
					}
				}
				else
				{
					loc.push(j);
					root->val = inorder[j];
					s.push(root);
				}

				break;
			}
		}
	}
	
	return root;
}
/*
递归的方法：
需要应用到哈希映射
*/
int main()
{
	TreeNode* root = buildTree(pre, in);
	Print(root);
	system("pause");
	return 0;
}
