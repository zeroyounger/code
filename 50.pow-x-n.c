/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (36.39%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    117.7K
 * Total Submissions: 323.5K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start


double myPow(double x, int n){
    long int y=n;
    bool f=false;
    if(y<0){
        f=true;
        y=-y;
    }
    double ans=1;
    while(y){
        if(y&1) ans*=x;
        x*=x;
        y>>=1;
    }
    return f?1/ans:ans;
}


// @lc code=end

