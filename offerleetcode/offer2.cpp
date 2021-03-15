/*
@time:2021-03-15
@author:gyl
@serise:offer1
@problem:在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。


*/
#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
执行用时：
28 ms

内存消耗：
12.8 MB

*/
/*
该方法采用每一行二分查找的方法，注意特殊情况
*/
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
    //判断特殊情况 重要！
    if(matrix.size()==0)
    {
        return false;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    //对每一行进行二分查找
    for(int i=0;i<n;i++)
    {
        int low = 0;
        int high = m;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(target == matrix[i][mid])
            {
                return true;
            }
            else if(target > matrix[i][mid])
            {
                low = mid+1;
            }
            else if(target <matrix[i][mid])
            {
                high = mid;//考虑到high要大于low的情况，不能减一
            }
        }
    }
    
    return false;
}
/*官方线性
执行用时：
32 ms

内存消耗：
12.6 MB

*/
/*
该方法的重点是，开始遍历的起点
遍历的起点是matrix[0][j-1]，而不是matrix[n/2][m/2]
因为从matrix[0][j-1]往下看，是一颗二叉搜索树
*/
bool findNumberIn2DArray_officail(vector<vector<int>>& matrix, int target) 
{
    if(matrix.size()==0)
    {
        return false;
    }
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = m-1;
    while(i<n&&j>=0)
    {
        int root = matrix[i][j];
        if(target == root)
        {
            return true;
        }
        else if(target>root)
        {
            i++;
        }
        else if(target<root)
        {
            j--;
        }
    }
    return false;
}