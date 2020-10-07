/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
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
vector<int> treenum{ 3,9,20,NULL,NULL,15,7 };
TreeNode* create(vector<int> data, int index, int n)
{
	if (index >= n || data[index] == NULL)
		return NULL;
	TreeNode* root = new TreeNode(NULL);
	root->val = data[index];
	root->left = create(data, 2 * index + 1, n);
	root->right = create(data, 2 * index + 2, n);

	return root;
}
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> ans{};
	vector<int> tmp;
	if (root == NULL)
		return ans;
	queue<TreeNode*> q;
	q.push(root);
	int size = 0;
	while (!q.empty())
	{
		size = q.size();
		while (size > 0)
		{
			
			tmp.push_back(q.front()->val);
			if (q.front()->left)
			{
				q.push(q.front()->left);
			}
			if (q.front()->right)
			{
				q.push(q.front()->right);
			}
			size = size - 1;
			q.pop();
		}
		ans.push_back(tmp);
		tmp.clear();
	}
	return ans;
}
int main()
{
	vector<vector<int>> havetry;
	//vector<int> tmp1;
	//tmp1.push_back(2);
	//tmp1.push_back(3);
	//vector<int> tmp2;
	//tmp2.push_back(5);
	//vector<int> tmp3;
	//tmp3.push_back(9);
	//tmp3.push_back(10);
	//havetry.push_back(tmp1);
	//havetry.push_back(tmp2);
	//havetry.push_back(tmp3);
	int length = std::end(treenum) - std::begin(treenum);
	TreeNode* root = create(treenum, 0, length);
	havetry = levelOrder(root);
	for (vector<vector<int>>::iterator it = havetry.begin(); it != havetry.end(); ++it)
	{
		for (int i = 0; i < (*it).size(); ++i)
			cout << (*it)[i] << " " ;
		cout << endl;
	}


	system("pause");
	return 0;
}