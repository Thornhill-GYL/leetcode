/*
@time:2002-11-09
@author:gyl
@series:每日一题
@problem: 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<vector<int>> inputnum{{3,3},{5,-1},{-2,4}};
int leng_zero(vector<int> single_num)
{
    return pow(single_num[0],2)+pow(single_num[1],2);
}
void Print_twovev(vector<vector<int>> num)
{
    for(vector<vector<int>>::iterator it = num.begin();it != num.end(); ++it)
    {
        for(int i=0;i<(*it).size();++i)
        {
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    }
}
//超时了
//不能冒泡排序了 ，要用快排才行
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    vector<vector<int>> ans {};
    for(int i=0;i<points.size()-1;i++)
    {
        for(int j=0;j<points.size()-1-i;j++)
        {
            if(leng_zero(points[j])> leng_zero(points[j+1]))
            {
                swap(points[j],points[j+1]);
            }
        }
    }
    Print_twovev(points);

    for(int i=0;i<K;i++)
    {
        ans.push_back(points[i]);
    }
    return ans;
    

}
//快排
/*执行用时：
248 ms
内存消耗：
43.1 M
*/
//方法：在快排的时候 就开始计算前面排列好多少个了，然后差不多拍好之后就可以返回了
 void quick_sort(vector<vector<int>>& a,int l,int r,int k)
 {
        if(l >= r) return ;
        int i = l - 1,j = r + 1;
        auto x = a[l + r >> 1];//l+r>>1 意味着除以2取整，也就是获取中间的数组
        int sum = x[0] * x[0] + x[1] * x[1];
        cout<<sum<<endl;
        while(i < j){
            do i++; 
            while(a[i][0] * a[i][0] + a[i][1] * a[i][1] < sum);
            do j--; 
            while(a[j][0] * a[j][0] + a[j][1] * a[j][1] > sum);
            if(i < j) 
            swap(a[i],a[j]);
        }
        int s = j - l + 1;//目前排列的前S个
        if(s >= k) 
        {
            return quick_sort(a,l,j,k);
        }
        
        else 
        {
            return quick_sort(a,j+1,r,k-s);
        }
 }
vector<vector<int>> quick_kClosest(vector<vector<int>>& points, int K) 
{
    
        vector<vector<int>> res {};
        quick_sort(points,0,points.size() - 1,K);
        for(int i = 0;i < K;i++){
            res.push_back(points[i]);
        }
        return res;

}
int main()
{
    vector<vector<int>> ans = quick_kClosest(inputnum,2);
    cout<<"ans:"<<endl;
    Print_twovev(ans);
    system("pause");
    return 0;


}