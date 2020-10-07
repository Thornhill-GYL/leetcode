/*
@time:2020-08-31
@author:gyl
@problem:
����һ����������������ڵ�ֵ�ľ���β�α�����
�����ȴ������ң��ٴ������������һ�������
�Դ����ƣ������֮�佻����У���
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
ʹ����������
һ��������Ĳ�α���
һ���淴��Ĳ�α���
ִ����ʱ��0ms
�ڴ����ģ�11.6 MB
*/
//vector<vector<int>> zigzagLevelOrder(TreeNode* root)
//{
//	vector<vector<int>> ans{};
//	vector<int> floor{};
//	if (root == NULL)
//		return ans;
//	queue<TreeNode*> pnormal;//����
//	queue<TreeNode*> qrever;//����
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
˫�˶��н��д���
ע��ǰ�ţ���ţ�ǰȡ�ͺ�ȡ
ִ����ʱ: 0 ms
�ڴ�����: 11.3 MB

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
			
			if (layer % 2 == 0)//Ϊż���㣺���Ϊ����
			{
				floor.push_back(de.front()->val);//���Ϊ������һֱ���������ǰ��
				//����ǰ��ǰ��Ԫ�ص����������Ӻ����������Ƚ��ȳ������
				if (de.front()->left)
				{
					de.push_back(de.front()->left);
				}
				if (de.front()->right)
				{
					de.push_back(de.front()->right);
				}
				de.pop_front();//ÿ�ν����׵���
			}
			else//����������Ϊ����
			{
				floor.push_back(de.back()->val);//������ż�����ʱ����������ţ�����Ҫ�Ӻ����ȡԪ��
			
				if (de.back()->right)//�Ӷ�β��ȡԪ�أ����������������������,ʵ���Ƚ������ģʽ
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
