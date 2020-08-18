/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (53.51%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    32.1K
 * Total Submissions: 60K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start


int min(int a, int b, int c){
	int min=a;
	if(b<min) min=b;
	if(c<min) min=c;
	return min;
}

int nthUglyNumber(int n){
    int i = 0;
    int ret = 1;
    int t2=0, t3=0, t5=0;
    int tmp[2048] = {0};
    tmp[0] = 1;
    for(i=1; i<n; i++) {
        ret = min(tmp[t2]*2, tmp[t3]*3, tmp[t5]*5);
        if(ret == tmp[t2]*2) t2++;
        if(ret == tmp[t3]*3) t3++;
        if(ret == tmp[t5]*5) t5++;
        tmp[i] = ret;
    }
    return ret;
}

// @lc code=end

