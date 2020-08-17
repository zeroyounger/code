/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.50%)
 * Likes:    2575
 * Dislikes: 0
 * Total Accepted:    348.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start

int expand(char * s, int l, int r){//以l和r为中心，向外的回文串最大字符数
    while(l>=0 && r<strlen(s) && s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}

char * longestPalindrome(char * s){
    if (strlen(s)==0) return "";
    int umax = 1, umid = 0, size=strlen(s);
    for (int i=0; i<size-1; i++){
        int temp = fmax(expand(s,i,i+1), expand(s,i,i));//aa是回文串，a也是回文串
        if ((temp>umax) && temp>1){
            umid=i;
            umax=temp;
        }
    }
    int l=umid-(umax-1)/2;
    int r=umid+umax/2+1;
    char *ans = (char*)malloc(sizeof(char)*(r-l+1));
    memset(ans,0,r-l+1);
    strncpy(ans,s+l,r-l);
    return ans;
}


// @lc code=end

