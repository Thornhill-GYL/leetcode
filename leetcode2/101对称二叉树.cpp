/*
@time:2020-08-28
@author:gyl
@problem:(101)����һ����������������Ƿ��Ǿ���ԳƵġ�
		 ���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
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
@�Լ�д��
�÷������õ��ǲ�α�����˼��
���ڶԳ��ԣ����԰���ÿһ�����ݵ�����Ҳ���ڹ���
������Ҫע����ǣ��е��ӽڵ�Ϊ�յ������
���������ȺͲ����ӽڵ�Ĳ��������жϡ�
ִ����ʱ: 1216 ms
�ڴ�����: 364.3 MB
�Ҵ�ʹ���û������������ ��̫ɵ�� ������
����һ������ͬʱ�����ҽڵ� ��̫ɵ�� ������
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
@�ݹ�ķ���
�÷����ǵݹ�ķ�����
���ǵ���������������ͬ��ֵ
ÿ������������������һ����������������Գ�
��ͬ���ƶ�������ָ��ķ����������������
pp ָ��� qq ָ��һ��ʼ��ָ��������ĸ���
��� pp ����ʱ��qq ���ƣ�pp ����ʱ��qq ���ơ�
ÿ�μ�鵱ǰ pp �� qq �ڵ��ֵ�Ƿ���ȣ����������ж����������Ƿ�Գơ�
ִ����ʱ��8 ms
�ڴ����ģ�12.4 MB
*/
//bool check(TreeNode* p, TreeNode* q)
//{
//	//���ȱȽ��������ڵ��Ƿ����
//	if (p == NULL && q == NULL)
//		return true;
//	//�����һ��Ϊ����Ϊ��
//	if (p ==NULL || q == NULL)
//		return false;
//	return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
//
//}
/*
@�����ķ�����
ͬ���ö��н��б���
���ǻ��Ǵ��������߿�ʼɨ��
Ȼ��Ƚ������Ƿ����
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