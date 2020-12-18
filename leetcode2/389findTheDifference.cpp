/*
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"
示例 3：

输入：s = "a", t = "aa"
输出："a"
示例 4：

输入：s = "ae", t = "aea"
输出："a"
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s = "aa";
string t = "aaa";
char findTheDifference(string s, string t) 
{
          vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a']++;
        }
        for (char ch: t) {
            cnt[ch - 'a']--;
            if (cnt[ch - 'a'] < 0) {
                return ch;
            }
        }
        return ' ';
    }
}
int main()
{
    char ans = findTheDifference(s,t);
    string::size_type rest;
    rest = s.find('a');
    cout<<rest<<endl;
    system("pause");
    return 0;
}