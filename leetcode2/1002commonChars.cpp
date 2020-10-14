/*
@time:2020-10-14
@author:gyl
@series:每日一题
@problem:给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。
示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
*/
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<string> A{ "bbddabab","cbcddbdd","bbcadcab","dabcacad","cddcacbc","ccbdbcba","cbddaccc","accdcdbb" };
//vector<string> commonChars(vector<string>& A) {
//
//}
/*
执行用时：
224 ms

内存消耗：
9.5 MB
方法：
用第一个字符串中的所有char进行遍历
记录包含自己在内的，相同字符串出现的次数
建立结果数组时，将相应的字符和次数进行添加。
需要注意的是，添加是需要查看结果数组中是否出现过相同的字符，以免重复添加。

*/
/*
别人的算法还有hash法需要掌握
*/
bool samechar(string a, vector<string> num)
{
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == a)
		{
			return true;
		}
		
	}
	return false;
}
int main()
{
	vector<int> remvec{ };
	int count_num = 0;
	vector<string> ans{};
	for (int i = 0; i < A[0].size(); i++)
	{
		remvec.clear();
		for (int j = 0; j < A.size(); j++)
		{
			count_num = 0;
			for (int k = 0; k < A[j].size(); k++)
			{
				if (A[0][i] == A[j][k])
				{
					count_num += 1;
				}
	
		
			}
			remvec.push_back(count_num);
			
		}
		vector<int>::iterator min_time = min_element(remvec.begin(), remvec.end());
		
		if (*min_time !=0)
		{

			string ansstr(1, A[0][i]);
			/*ansstr.push_back(A[0][i]);*/
			if (ans.empty() || !samechar(ansstr,ans))
			{
				for (int m = 0; m < *min_time; m++)
				{
					ans.push_back(ansstr);
				}
			}
			/*ansstr.clear();*/
		}

	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	system("pause");
	
	return 0;
}