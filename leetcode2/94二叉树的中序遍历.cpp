/*
给定一个二叉树，返回它的中序 遍历。
@time:2020-08-26
@atuhter:gyl
@problem:二叉树的中序遍历（94题）
*/
#include<iostream>
#include <string>
#include <vector>
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
vector<int> treenum{ 1,2,2,3,3,NULL,NULL,4,4 };
TreeNode* create(vector<int> data, int index, int n)
{
	TreeNode* root = new TreeNode(NULL);
	if (index >= n || data[index] == NULL)
		return NULL;
	root->val = data[index];
	root->left = create(data, index * 2 + 1, n);
	root->right = create(data, index * 2 + 2, n);

	return root;
}
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> ans{};//这个地方的细节问题要注意
	if (root == NULL)
		ans.push_back(NULL);
	stack<TreeNode*> s;
	TreeNode* ptr = root;
	while (!s.empty() || ptr != NULL)
	{
		while (ptr!= NULL)
		{
			s.push(ptr);
			ptr = ptr->left;
		}
		if (!s.empty())
		{
			ptr = s.top();
			ans.push_back(ptr->val);
			s.pop();
			ptr = ptr->right;
		}
	}
	return ans;
}
int main()
{
	int length = 0;
	length = std::end(treenum) - std::begin(treenum);
	TreeNode* root = create(treenum, 0, length);
	vector<int> havetry = inorderTraversal(root);
	
	for (vector<int>::iterator ivector = havetry.begin(); ivector != havetry.end(); ivector++)
	{
		std::cout << (*ivector) << endl;
	}
	system("pause");
	return 0;
	
}
