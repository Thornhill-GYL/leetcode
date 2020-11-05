/*
@time:2020-11-05
@author:gyl
@series:每日一题
@problem：给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0
*/
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
尝试自己的方法 不太方便
官方的方法广度优先搜索 + 优化建图
我们可以把每个单词都抽象为一个点，如果两个单词可以只改变一个字母进行转换，那么说明他们之间有一条双向边。因此我们只需要把满足转换条件的点相连，就形成了一张图。
具体地，我们可以创建虚拟节点。对于单词 hit，我们创建三个虚拟节点 *it、h*t、hi*，并让 hit 向这三个虚拟节点分别连一条边即可。如果一个单词能够转化为 hit，那么该单词必然会连接到这三个虚拟节点之一。对于每一个单词，我们枚举它连接到的虚拟节点，把该单词对应的 id 与这些虚拟节点对应的 id 相连即可。

最后我们将起点加入队列开始广度优先搜索，当搜索到终点时，我们就找到了最短路径的长度。注意因为添加了虚拟节点，所以我们得到的距离为实际最短路径长度的两倍。同时我们并未计算起点对答案的贡献，所以我们应当返回距离的一半再加一的结果。
执行用时：
172 ms
内存消耗：
31.7 MB
2%

*/
unordered_map<string, int> wordId;
vector<vector<int>> edge;
int nodeNum = 0;
void addWord(string& word) 
{
    if (!wordId.count(word)) 
    {
        wordId[word] = nodeNum++;
        edge.emplace_back();
        }
}

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    int ans = 0;
    string temp ="";
    if(wordList.empty())
    {
        return 0;
    }
    int same_end_pos = -1;
    for(int i=0;i<wordList.size();i++)
    {
    }

}