/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.62%)
 * Likes:    1220
 * Dislikes: 0
 * Total Accepted:    336.4K
 * Total Submissions: 871.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";
    if(strsSize == 1) return strs[0];
    int j = 0;
    while(1){
        for(int i = 1; i < strsSize; i++)
            if(strs[0][j] != strs[i][j] || !strs[0][j] || !strs[i][j]){
                strs[0][j] = 0;
                return strs[0];
            }
        j++;
    }
    return NULL;
}


// @lc code=end

