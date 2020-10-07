/*
@time:2020-08-31
@author:gyl
@problem:
给定一个二叉树，返回其节点值的锯齿形层次遍历。
（即先从左往右，再从右往左进行下一层遍历，
以此类推，层与层之间交替进行）。
*/
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> treenum { 1,2,4,1,NULL,3,-1,5,1,NULL,NULL,NULL,6,NULL,8 };
TreeNode* create(vector<int> data, int index, int n)
{
	TreeNode* root = new TreeNode(NULL);
	if (index >= n || data[index] == NULL)
	{
		return NULL;
	}
		
	root->val = data[index];
	root->left = create(data, 2 * index + 1, n);
	root->right = create(data, 2 * index + 2, n);

	return root;
}
/*
使用两个队列
一个存正序的层次遍历
一个存反序的层次遍历
执行用时：0ms
内存消耗：11.6 MB
*/
//vector<vector<int>> zigzagLevelOrder(TreeNode* root)
//{
//	vector<vector<int>> ans{};
//	vector<int> floor{};
//	if (root == NULL)
//		return ans;
//	queue<TreeNode*> pnormal;//正序
//	queue<TreeNode*> qrever;//反序
//	pnormal.push(root);
//	qrever.push(root);
//	int size = 0;
//	int layer = 0;
//	while (!pnormal.empty() || !qrever.empty())
//	{
//		if (layer % 2 == 0)
//		{
//			size = pnormal.size();
//			floor.clear();
//			while (size > 0)
//			{
//				floor.push_back(pnormal.front()->val);
//				if (qrever.front()->right)
//					qrever.push(qrever.front()->right);
//				if (qrever.front()->left)
//					qrever.push(qrever.front()->left);
//				if (pnormal.front()->left)
//					pnormal.push(pnormal.front()->left);
//				if (pnormal.front()->right)
//					pnormal.push(pnormal.front()->right);
//
//				size = size - 1;
//				pnormal.pop();
//				qrever.pop();
//			}
//		}
//		else
//		{
//			size = qrever.size();
//			floor.clear();
//			while (size > 0)
//			{
//				floor.push_back(qrever.front()->val);
//				if (qrever.front()->right)
//					qrever.push(qrever.front()->right);
//				if (qrever.front()->left)
//					qrever.push(qrever.front()->left);
//				if (pnormal.front()->left)
//					pnormal.push(pnormal.front()->left);
//				if (pnormal.front()->right)
//					pnormal.push(pnormal.front()->right);
//					
//				size = size - 1;
//				qrever.pop();
//				pnormal.pop();
//			}
//		}
//		layer = layer + 1;
//		ans.push_back(floor);
//	}
//	return ans;
//}
/*
双端队列进行处理
注意前放，后放，前取和后取
执行用时: 0 ms
内存消耗: 11.3 MB

*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> ans{};
	vector<int> floor{};
	if (root == NULL)
	{
		return ans;
	}
	deque<TreeNode*> de;
	de.push_back(root);
	int size = 0;
	int layer = 0;
	while (!de.empty())
	{
		size = de.size();
		floor.clear();
		while (size > 0)
		{
			
			if (layer % 2 == 0)//为偶数层：输出为正序
			{
				floor.push_back(de.front()->val);//输出为正序，则一直输出队列最前端
				//将当前最前的元素的左右子树从后面正常（先进先出）入队
				if (de.front()->left)
				{
					de.push_back(de.front()->left);
				}
				if (de.front()->right)
				{
					de.push_back(de.front()->right);
				}
				de.pop_front();//每次将队首弹出
			}
			else//奇数层则是为逆序
			{
				floor.push_back(de.back()->val);//由于在偶数层的时候是正常存放，所以要从后面读取元素
			
				if (de.back()->right)//从队尾读取元素，并将其右左子树插入队首,实现先进后出的模式
					de.push_front(de.back()->right);
				if (de.back()->left)
					de.push_front(de.back()->left);
				de.pop_back();

			}
			size = size - 1;
			
	
		}
		layer = layer + 1;
		ans.push_back(floor);
	}
	return ans;
}
void Print(TreeNode* p)
{
	if (p == NULL)
		return;
	cout << p->val << endl;
	Print(p->left);
	Print(p->right);
}
int main()
{
	int length = std::end(treenum) - std::begin(treenum);
	TreeNode* root = create(treenum, 0, length);
	vector<vector<int>> havetry = zigzagLevelOrder(root);
	//Print(root);
	for (vector<vector<int>>::iterator it = havetry.begin(); it != havetry.end(); ++it)
	{
		for (int i = 0; i < (*it).size(); ++i)
			cout << (*it)[i] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
