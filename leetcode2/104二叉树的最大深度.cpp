//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>　　
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int treenum[] { 3, 9, 20, NULL, NULL, 15, 7 };
/*构建二叉树
该部分的构建二叉树使用的是层次遍历的数组构建的
其他的构建方法，之后会总结到另一个cpp中。
*/
TreeNode * creat(int data[], int index, int n)//建立二叉树
{
	TreeNode *newtree = new TreeNode(NULL);
	if (index >= n||data[index]==NULL)
		return NULL;
	newtree->val = data[index];
	newtree->left = creat(data, 2 * index + 1, n);
	newtree->right = creat(data, 2 * index + 2, n);

	return newtree;

}
void Print(TreeNode* p)
{
	if (p == NULL)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}
/*
利用分治法来求二叉树的最大深度
分治法也就是递归的方法

int maxDepth(TreeNode* root)
{
	int ans;
	if (root == NULL)
		return 0;
	int leftmax = maxDepth(root->left)+1;
	int rightmax = maxDepth(root->right)+1;
	ans = leftmax > rightmax ? leftmax : rightmax;
	return ans;

}*/

/*
使用BFS遍历进行广度搜索
使用队列对每层进行一个遍历
队列先进先出，将每层进行一个消耗
*/
int maxDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);//将root进队
	int ans = 0;
	while (!q.empty())
	{
		int sz = q.size();//记录一下每层的节点数
		while (sz > 0)//这个循环将下一层的节点入队，并对本层节点进行消耗
		{
		
			if (q.front()->left != NULL)
				q.push(q.front()->left);
			if (q.front()->right != NULL)
				q.push(q.front()->right);
			//以上是将下一层的节点全部入队。
			q.pop();//然后将本层节点弹出
			sz = sz - 1;//然后继续遍历本层节点，将其消耗完，进入下一层
		}
		ans += 1;
	}
	return ans;
}
int main()
{
	int length = std::end(treenum) - std::begin(treenum);
	std::cout << length << endl;
	TreeNode * root = creat(treenum, 0, length);
	/*Print(root);*/
	int depth = maxDepth(root);
	std::cout << depth << endl;
	system("pause");
	
}