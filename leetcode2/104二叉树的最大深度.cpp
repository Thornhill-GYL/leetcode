//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>����
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int treenum[] { 3, 9, 20, NULL, NULL, 15, 7 };
/*����������
�ò��ֵĹ���������ʹ�õ��ǲ�α��������鹹����
�����Ĺ���������֮����ܽᵽ��һ��cpp�С�
*/
TreeNode * creat(int data[], int index, int n)//����������
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
���÷��η������������������
���η�Ҳ���ǵݹ�ķ���

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
ʹ��BFS�������й������
ʹ�ö��ж�ÿ�����һ������
�����Ƚ��ȳ�����ÿ�����һ������
*/
int maxDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);//��root����
	int ans = 0;
	while (!q.empty())
	{
		int sz = q.size();//��¼һ��ÿ��Ľڵ���
		while (sz > 0)//���ѭ������һ��Ľڵ���ӣ����Ա���ڵ��������
		{
		
			if (q.front()->left != NULL)
				q.push(q.front()->left);
			if (q.front()->right != NULL)
				q.push(q.front()->right);
			//�����ǽ���һ��Ľڵ�ȫ����ӡ�
			q.pop();//Ȼ�󽫱���ڵ㵯��
			sz = sz - 1;//Ȼ�������������ڵ㣬���������꣬������һ��
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