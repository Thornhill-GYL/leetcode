/*
@time:2020-08-28
@author:gyl
@problem:(101)给定一个二叉树，检查它是否是镜像对称的。
		 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
			1
		   / \
		  2   2
		 / \ / \
		3  4 4  3
*/
#include<iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> treenum{ 2,3,3,4,5,5,4,NULL,NULL,8,9,9,8 };
//vector<int> treenum{ 1, 2, 2, NULL, 3, NULL, 3 };
TreeNode* create(vector<int> data, int index, int n)
{
	if (index >= n || data[index] == NULL)
	{
		return NULL;
	}
	TreeNode* root = new TreeNode(NULL);
	root->val = data[index];
	root->left = create(data, 2 * index + 1, n);
	root->right = create(data, 2 * index + 2, n);

	return root;
}

int maxdepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = maxdepth(root->left) + 1;
	int right = maxdepth(root->right) + 1;
	int ans = left > right ? left : right;
	return ans;
}
/*
@自己写的
该方法利用的是层次遍历的思想
由于对称性，所以包含每一层数据的数组也存在规律
不过需要注意的是，有的子节点为空的情况。
利用最大深度和补充子节点的操作进行判断。
执行用时: 1216 ms
内存消耗: 364.3 MB
我错就错在没有用两个队列 我太傻了 呜呜呜
或者一个队列同时存左右节点 我太傻了 呜呜呜
*/
//bool isSymmetric(TreeNode* root) 
//{
//	bool ans = true;
//	if (root == NULL||(root->left==NULL&&root->right==NULL))
//		return true;
//	queue<TreeNode*> q;
//	q.push(root);
//	int size = 0;
//	int countlayer = 0;
//	int maxdep = maxdepth(root);
//	vector<int> floor{};
//	while (!q.empty())
//	{
//		size = q.size();
//		floor.clear();
//		while (size > 0)
//		{
//			floor.push_back(q.front()->val);
//			if (countlayer<maxdep-1)
//			{ 
//				if (q.front()->left)
//				{
//					q.push(q.front()->left);
//				}
//				else 
//				{
//					TreeNode * left = new TreeNode(-1);
//					q.push(left);
//				}
//
//				if (q.front()->right)
//					q.push(q.front()->right);
//				else 
//				{
//					TreeNode * right = new TreeNode(-1);
//					q.push(right);
//				}
//			}
//
//			size = size - 1;
//			q.pop();
//			
//		}
//		int length = std::end(floor) - std::begin(floor);
//		if (length == pow(2, countlayer))
//		{
//			if (length != 1)
//			{
//				for (int i = 0; i < (length / 2); i++)
//				{
//					if (floor[i] == floor[(length - 1 - i)])
//						ans = true;
//					else
//					{
//						return false;
//					}
//				}
//			}
//		}
//		else
//			return false;
//		countlayer = countlayer + 1;
//
//	}
//	return ans;
//}
/*
@递归的方法
该方法是递归的方法：
它们的两个根结点具有相同的值
每个树的右子树都与另一个树的左子树镜像对称
「同步移动」两个指针的方法来遍历这棵树，
pp 指针和 qq 指针一开始都指向这棵树的根，
随后 pp 右移时，qq 左移，pp 左移时，qq 右移。
每次检查当前 pp 和 qq 节点的值是否相等，如果相等再判断左右子树是否对称。
执行用时：8 ms
内存消耗：12.4 MB
*/
//bool check(TreeNode* p, TreeNode* q)
//{
//	//首先比较两个根节点是否相等
//	if (p == NULL && q == NULL)
//		return true;
//	//如果有一边为空则为假
//	if (p ==NULL || q == NULL)
//		return false;
//	return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
//
//}
/*
@迭代的方法：
同样用队列进行保存
但是还是从树的两边开始扫描
然后比较左右是否相等
8 ms	12.9 MB
*/
bool check(TreeNode* u, TreeNode* v)
{
	queue<TreeNode*> q;
	q.push(u);
	q.push(v);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		v = q.front();
		q.pop();
		if(u==NULL&&v==NULL)
			continue;
		if (u == NULL || v == NULL || u->val != v->val)
			return false;
		q.push(u->left);
		q.push(v->right);

		q.push(u->right);
		q.push(v->left);
	}
	return true;
}
bool isSymmetric(TreeNode* root)
{
	return check(root, root);
}

int main()
{
	int len = std::end(treenum) - std::begin(treenum);
	TreeNode* root = create(treenum, 0, len);
	bool havetry = isSymmetric(root);
	std::cout << boolalpha<<havetry<< endl;
	system("pause");
	return 0;
}