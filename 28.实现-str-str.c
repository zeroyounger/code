/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.67%)
 * Likes:    534
 * Dislikes: 0
 * Total Accepted:    215.2K
 * Total Submissions: 542.4K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start


int strStr(char * haystack, char * needle){
    int len2 = strlen(needle);
    if (!len2) return 0;
    int len1 = strlen(haystack), j;
    for (int i = 0; i <= len1 - len2; i++)
        if (haystack[i] == needle[0] && haystack[i + len2 - 1] == needle[len2 - 1]){
            for (j = 1; j < len2; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == len2)
                return i;
        }
    return -1;
}

// @lc code=end

