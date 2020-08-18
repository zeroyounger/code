/*
 * @lc app=leetcode.cn id=227 lang=c
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (36.85%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 59.2K
 * Testcase Example:  '"3+2*2"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
 * 
 * 示例 1:
 * 
 * 输入: "3+2*2"
 * 输出: 7
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 3/2 "
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: " 3+5 / 2 "
 * 输出: 5
 * 
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */

// @lc code=start


int ss(int i,char s[],int n) {
    if(i==n)
        return 0;
    int a=0;
    char cc='+';
    if(s[i]=='+')
        i++;
    if(s[i]=='-'){
        cc='-';
        i++;
    }
    while(i<n&&s[i]<='9'&&s[i]>='0') {
        a*=10;
        a+=s[i]-'0';
        i++;
    }
    while(s[i]=='*'||s[i]=='/') {
        char c=s[i];
        i++;
        double b=0;
        while(i<n&&s[i]<='9'&&s[i]>='0') {
            b*=10;
            b+=s[i]-'0';
            i++;
        }
        if(c=='*')
            a*=b;
        else
            a/=b;
    }
    if(cc=='+') 
        return ss(i,s,n)+a;
    return ss(i,s,n)-a;
}
int calculate(char * s){
    int n=strlen(s);
    int m=0;
    for(int i=0;i<n;i++){
        if(s[i]!=' ')
        s[m++]=s[i];
    }
    s[m]='\0';
    return ss(0,s,m);
}
// @lc code=end

