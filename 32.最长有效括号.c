/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (33.54%)
 * Likes:    909
 * Dislikes: 0
 * Total Accepted:    94.4K
 * Total Submissions: 281.4K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start

int longestValidParentheses(char * s){
    int  left=0,right=0,max=0;
    char *ts=s;
    while(*s){
        if(*s=='(')
            left++;
        else{
            right++;
            if(left==right)
                max=left>max?left:max;
            else if(left<right){
                left=0;
                right=0;
            }
        }
        s++;
    }
    s--;
    left=right=0;
    while(s>=ts){
        if(*s==')')
            left++;
        else{
            right++;
            if(left==right)
                max=left>max?left:max;
            else if(left<right){
                left=0;
                right=0;
            }
        }
        s--;
    }
    return max*2;
}

// @lc code=end

