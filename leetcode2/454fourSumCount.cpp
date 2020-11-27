/*
@time:2020-11-27
@author:gyl
@series:每日一题
@problem:给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
vector<int> A {1,2};
vector<int> B {-2,-1};
vector<int> C {-1,2};
vector<int> D {0,2};
/*
执行用时：
396 ms
内存消耗：
29 MB
这道题不会 看的题解
用到了哈希表，要去学习一下
总结，看到形如：A+B....+N=0的式子，要转换为(A+...T)=-((T+1)...+N)再计算，这个T的分割点一般是一半，特殊情况下需要自行判断。定T是解题的关键。
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
 {
     unordered_map<int, int> countAB ;
       for (int u: A) {
            for (int v: B) {
                ++countAB[u + v];//这个地方是在记录相同值得数目！
            }
        }
    int ans = 0;
    for(int u:C)
    {
        for(int v:D)
        {
            int tmp = countAB.count(-u-v);//count的作用是在检查countAB中是否有与-v-u相同的值
            if(countAB.count(-u-v))
            {
                ans+=countAB[-u-v];//对应的有几个相同的 则增加几个
            }
        }
    }
        // 遍历输出 countAB 容器中所有的键值对
    // for (auto iter = countAB.begin(); iter != countAB.end(); ++iter) {
    //      cout << "<" << iter->first << ", " << iter->second << ">" << endl;
    // }
    return ans;
}
int main()
{
     int ans = fourSumCount(A,B,C,D);
    cout<<ans<<endl;

    system("pause");
    return 0;
}