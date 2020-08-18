/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (57.39%)
 * Likes:    553
 * Dislikes: 0
 * Total Accepted:    79.6K
 * Total Submissions: 138.8K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

// @lc code=start


int isSquares(int n){
    int num = (int)sqrt(n);
    return num*num==n;
}
int numSquares(int n){
    int j;
    int max;
    while(n%4==0)
        n /= 4;
    if(n%8==7)
        return 4;
    if(isSquares(n))
        return 1;
    max = (int)sqrt(n);
    for(j = max;j>=max/2;j--)
        if(isSquares(n-j*j))
            return 2;
    return 3;
}

// @lc code=end

