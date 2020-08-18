/*
 * @lc app=leetcode.cn id=214 lang=c
 *
 * [214] 最短回文串
 *
 * https://leetcode-cn.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (32.39%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 33.3K
 * Testcase Example:  '"aacecaaa"'
 *
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
 * 
 * 示例 1:
 * 
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "abcd"
 * 输出: "dcbabcd"
 * 
 */

// @lc code=start


char anw[200000]; 
char* shortestPalindrome(char* s) {
    int len = strlen(s);
    if(len==0) {
        anw[0]='\0';
        return anw;
    }
    int t[200000];
    t[0]=-1;
    int j=0,k=-1;int maxx=0;
    while(j<len-1){
        while(k>=0&&s[k]!=s[len-1-j]) {
            k=t[k];
        }   
        j++;
        k++;
        t[j]=k;
    }
    maxx=t[len-1]+1;
    int kind=1;
    for(int i=0;i<len/2;i++) {
        if(s[i]!=s[len-1-i]) {
            kind=0;
            break;
        }
    }
    if(kind)
        maxx=len;
    for(int i=0;i<len-maxx;i++)
        anw[i]=s[len-1-i];
    for(int i=len-maxx;i<2*len-maxx;i++)
        anw[i]=s[i-len+maxx];
    anw[2*len-maxx]='\0';
    return anw; 
}

// @lc code=end

