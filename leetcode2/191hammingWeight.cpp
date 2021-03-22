/*
@time:2021-3-22
@author:gyl
@series:每日一题(简单)
@problem:编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。

 

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 3 中，输入表示有符号整数 -3。
 

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
一般的思想 就是把它转化为二进制看看是否为1
0 ms	5.9 MB
*/
int hammingWeight(uint32_t n) {
        int sum = 0;
       
        for(int i=0;i<32;i++)
        {
    
            int num = n%2;
            n = n/2;

            if(num==1)
            {
                sum++;
            }
        }
        return sum;
    }
/*
使用位运算
4 ms	5.8 MB
*/
int hammingWeight_off1(uint32_t n)
{
     int ans = 0;
        for(int i=0;i<32;i++)
        {
            
            if(n&(1<<i))//1<<i左移运算   =》2^i
            {
                
                ans++;
            }
        }
        return ans;

}
/*
0 ms	5.9 MB
根据n&n-1 : 6&(6-1) => 6(110) & 5(101) = 4 (100)  可以将n中的最低位的1转换为0，一直转换直到为0
*/
int hammingWeight_off2(uint32_t n)
{
    int ans =0;
        while(n)
        {
            n = n&(n-1);
            ans++;
        }
        return ans;

}
