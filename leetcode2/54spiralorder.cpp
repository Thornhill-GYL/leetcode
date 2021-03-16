/*
@time:2021-3-15
@author:gyl
@series:每日一题
@problem:给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    if(matrix.size()==0||matrix[0].size()==0)
    {
        return {};
    }
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int left=0,right = col-1;//确定最开始列的左界限，右界限
    int top=0,bottom = row-1;//确定最开始行的上界限，下界限
    while(left<=right&&top<=bottom)
    {
        for(int col = left;col<=right;col++)//最外圈的行
        {
            ans.push_back(matrix[top][col]);
        }
        for(int row = top+1;row<=bottom;row++)//最外面的列
        {
            ans.push_back(matrix[row][right]);
        }
        if(left<right&&top<bottom)//这里的条件限制是针对下面的条件限制
        {
            for(int col = right-1;col>left;col--)//最外面的下面层
            {
                ans.push_back(matrix[bottom][col]);
            }
            for(int row=bottom;row>top;row--)
            {
                ans.push_back(matrix[row][left]);
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return ans;

}