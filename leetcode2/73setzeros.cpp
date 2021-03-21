/*
@time:2021-3-18
@author:gyl
@series:每日一题(中等)
@problem:给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
法1
采用初始化两个数组的方法，先存储矩阵中为0的位置
16 ms	12.9 MB
*/
void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size());
        vector<int> line(matrix[0].size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    line[j]=1;
                }
            }
        }
            
            
                for(int i=0;i<matrix.size();i++)
                {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                        if(row[i]==1||line[j]==1)
                        {
                            matrix[i][j]=0;
                        }
                    }
                }
            
        
        
    }
void setZeroes_offical2(vector<vector<int>>& matrix)
{
    bool f1raw=false;//标注第一行是否有包含0
    bool f1line = false;//标注第一列是否包含0
    for(int i=0;i<matrix.size();i++)
    {
        if(matrix[i][0]==0)
        {
            f1line = true;
        }
    }
    for(int j=0;j<matrix[0].size();j++)
    {
        if(matrix[0][j])
        {
            f1raw = true;
        }
    }
    
    for(int i=1;i<matrix.size();i++)
    {
        for(int j = 1;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0] = 0;
                matrix[0][j]=0;
            }
        }
    }

    for(int i=1;i<matrix.size();i++)
    {
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[i][0]==0||matrix[0][j]==0)
            {
                matrix[i][j]=0;
            }
        }
    }

    if(f1raw==true)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            matrix[0][j]=0;
        }
    }
    if(f1line==true)
    {
        for(int i = 0;i<matrix.size();i++)
        {
            matrix[i][0]=0;
        }
    }
}/*
我们可以对方法二进一步优化，只使用一个标记变量记录第一列是否原本存在 00。这样，第一列的第一个元素即可以标记第一行是否出现 00
但为了防止每一列的第一个元素被提前更新，我们需要从最后一行开始，倒序地处理矩阵元素


*/
void setZeroes_off3(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++)
         {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0) {
                matrix[i][0] = 0;
            }
        }
    }
