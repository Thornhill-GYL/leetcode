/*
@time:2020-10-14
@author:gyl
@series:ÿ��һ��
@problem:��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�

����԰�����˳�򷵻ش𰸡�
ʾ�� 1��

���룺["bella","label","roller"]
�����["e","l","l"]
ʾ�� 2��

���룺["cool","lock","cook"]
�����["c","o"]
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
ִ����ʱ��
224 ms

�ڴ����ģ�
9.5 MB
������
�õ�һ���ַ����е�����char���б���
��¼�����Լ����ڵģ���ͬ�ַ������ֵĴ���
�����������ʱ������Ӧ���ַ��ʹ���������ӡ�
��Ҫע����ǣ��������Ҫ�鿴����������Ƿ���ֹ���ͬ���ַ��������ظ���ӡ�

*/
/*
���˵��㷨����hash����Ҫ����
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