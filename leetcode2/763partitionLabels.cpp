/*
@time:2020-10-22
@author:gyl
@series:每日一题
@proble:763字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
//string S = "aedbdeddac";
//string S = "caedbdeddac";
string S = "mababcbacaudefegdehijhklij";
//string S = "aebmlddd";
/*
自己的蠢方法
执行用时：
84 ms

内存消耗：
7.3 MB

首先外循环从前循环，内循环从后循环，记录每个字符最后出现的位置（number）
再次循环number，以第一个最后出现的位置作为节点，开始查看中间是否有大于该位置的字符
若有则将界限进行替换。
该方法的问题在于第一个字符作为单字符的情况处理。

*/
vector<int> partitionLabels(string S)
 {
     
     vector<int> number{};
	 vector<int> ans{};
     int i=0;
	 int new_size = 0;
     while(i<S.size())
     {
         for(int j = S.size()-1;j>=0;j--)//从后往前遍历，查找字符最后出现的位置
         {
             if(S[i]==S[j])
             {
                 number.push_back(j);
                 break;
             }
         }
         
         i++;
     }
	 int j = 0;
	 i = 0;
	 int less = 0;
	 int first_char = 0;
	 while (i <S.size())
	 {
		
		 new_size = number[i];
		 while (j <= new_size)
		 {
			 if (new_size == 0)//单独处理第一个字符作为单字符的情况
			 {
				 j++;
				 first_char = 1;
				 break;
				 
			 }
			 if (number[j] > new_size)//查看字符的出现位置是否比界限大
			 {
				 new_size = number[j];//大则替换
			 }
			 j++;
		 }
	
		 if (less == 0)
		 {
			 
			 ans.push_back(new_size + 1);
		 }
		 else if (first_char == 1 && less == -1)//处理单字符作为首字符的情况
		 {
			 ans.push_back(new_size);
		 }
		 else
		 {
			 ans.push_back(new_size - less);
			 
		 }
		 if (new_size == 0)
		 {
			 less = -1;
		 }
		 else
		 {
			 less = new_size;
		 }
		 
		 
		 
		 i = j ;
		 
	 }
	 
	
     return ans;
 }
//官方算法：贪心算法+双指针，等我搞这个模块的时候再说
int main()
{
    vector<int> show = partitionLabels(S);
	for (int i = 0; i < show.size(); i++)
	{
		cout << show[i] << endl;
	}
	system("pause");
    return 0;
}