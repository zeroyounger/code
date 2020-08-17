/*
 * @lc app=leetcode.cn id=97 lang=c
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (45.24%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    34.2K
 * Total Submissions: 75.6K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出：false
 * 
 */

// @lc code=start


bool isInterleave(char * s1, char * s2, char * s3){
    if(strlen(s3) != strlen(s1) + strlen(s2)) return false;
    if(strlen(s1) == 0 ) return (!strcmp(s2,s3));
    if(strlen(s2) == 0 ) return (!strcmp(s1,s3));
    if(strlen(s3) == 0 ) return true;
    int dp[strlen(s1) + 1][strlen(s2) + 1]; 
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= strlen(s1); ++i)
        dp[i][0] = (s1[i-1] == s3[i-1] && dp[i-1][0]);
    for(int j = 1; j <= strlen(s2); ++j)
        dp[0][j] = (s2[j-1] == s3[j-1] && dp[0][j-1]);
    for(int i = 1; i <= strlen(s1); ++i){  
        for(int j = 1; j <= strlen(s2); ++j){
            dp[i][j] = ((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]));
        }
    }
    return dp[strlen(s1)][strlen(s2)];
}


// @lc code=end

