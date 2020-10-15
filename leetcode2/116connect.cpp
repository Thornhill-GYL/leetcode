/*
@time:2020-10-15
@authur:gyl
@seriel:每日一题 
@problem：
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <math.h>
#include <list>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
/*
80 ms	17.4 MB
利用了树的层次遍历
将层次遍历存入数组中
对每一层进行操作，每个节点的next就是下一个元素
需要注意的是，在指向下一个元素的时候，注意超界的问题
*/
 Node* connect(Node* root) 
 {
     vector<Node*> li;
     if(root==NULL)
     {
         return;
     }
     root->next = NULL;
     li.push_back(root);
     int size =0;
     int size_over=0;
     while(!li.empty())
     {
        size = li.size();
         while(size>0)
         {
             if(li.front()->left)
             {
                li.push_back(li.front()->left);
             }
             if(li.front()->right)
             {
                 li.push_back(li.front()->right);
             }
             size = size-1;
            li.erase(li.begin());
         }
         size_over = li.size();
         for( int i=0;i<size_over;i++)
         {
             if(i+1>=size_over)
             {
                 li[i]->next = NULL;
             }
             else
             {
                 li[i]->next = li[i+1];
             }
             
             
         }
         
     }
     return root;
 }