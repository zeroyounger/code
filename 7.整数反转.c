/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.60%)
 * Likes:    2109
 * Dislikes: 0
 * Total Accepted:    436.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start


int reverse(int x){
    int ans = 0;
    while(x!=0){
        int pop=x%10;
        //在执行操作前先判断是否会溢出，如果溢出，则函数直接返回0
        //INT_MAX和INT_MIN的使用
        if(ans>INT_MAX /10||(ans==INT_MAX/10 && pop>7)) return 0;
        if(ans<INT_MIN/10||(ans==INT_MIN/10 && pop<-8)) return 0;
        ans = ans*10+pop;
        x/=10;
    }
    return ans;
}


// @lc code=end

