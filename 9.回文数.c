/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.47%)
 * Likes:    1186
 * Dislikes: 0
 * Total Accepted:    423.1K
 * Total Submissions: 723.6K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start


bool isPalindrome(int x){
    int y = x ;  //用y记住原先值
    long res=0;  //直接定义为long型，用于存储翻转后的数据，因为int型取值范围内倒转可能会溢出
    while(x > 0){
         res = res*10 + x%10;   
         x = x/10;   
    }
    if(res == y) return true;
    return false;
}


// @lc code=end

