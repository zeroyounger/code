/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.42%)
 * Likes:    4178
 * Dislikes: 0
 * Total Accepted:    617K
 * Total Submissions: 1.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start


int lengthOfLongestSubstring(char * s){
    int prior = 0; //上次状态下最长子串的长度
    int dict[256] = {0}; //映射ASCII码
    int i;
    for (int left = 0, right = 1; *s != '\0'; right++){
        i = *s-0; //字符转换为整数
        if(dict[i] > left)    
            left = dict[i];
        dict[i] = right;
        prior = (prior>right-left)?prior:right-left; //right的值比对应的数组下标大1
        s++;
    }
    return prior;
}
// @lc code=end

