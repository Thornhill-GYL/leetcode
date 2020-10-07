/*@time:2020-09-02
@author:gyl
@problem:(105)����һ������ǰ�������������������������
ע��: ����Լ�������û���ظ���Ԫ�ء�
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
ʹ������ջ����������⣨�Լ���ģ�
��ٷ��ĵڶ��ַ�����ͬ

ջs������ÿ�θ��ƵĽڵ�
ջloc������ÿ����ȵ�λ��
�����ҵ�root��λ�ã���������ջ��������
��ǰ��ʼ�������ҵ�����������ͬ�Ľڵ�
������λ���뵱ǰλ��ջ��top�Ƚ�
С����ڵ�
��һֱ�ҵ��ȸ�λ�ø���Ľڵ��λ��
	Ȼ��ýڵ���ǰһ�����ҽڵ㡣
ִ����ʱ��332 ms ������ C++ �ύ�л����� 5.05%���û�
�ڴ����ģ�17.4 MB, ������ C++ �ύ�л�����72.24%���û�
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
					if (j < loc.top())//����ͬʱ������λ��С�ڵ�ǰջ����λ�ã������Ǹýڵ����ڵ�
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
	
						while (!loc.empty()&&j > loc.top()&&!s.empty())//������ջ��λ�ã����ҵ�ǰջ��Ϊ�գ���ֹ������root�ڵ�֮��ʧ�ص������
						{
							tmp = s.top();//��¼popǰ��ջ�����ýڵ�Ϊ֮�󴴽�������
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
�ݹ�ķ�����
��ҪӦ�õ���ϣӳ��
*/
int main()
{
	TreeNode* root = buildTree(pre, in);
	Print(root);
	system("pause");
	return 0;
}
