/*
 * @lc app=leetcode.cn id=29 lang=c
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (20.08%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    58.9K
 * Total Submissions: 293.6K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start


int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    if(divisor == INT_MIN) return 0;
    bool flag = false;
    if (dividend == INT_MIN) {
        flag = true;
        //除数超大，分成 dividend - divisor + divisor，商变成 new-dividend + 1
        dividend += abs(divisor);
    }
    bool sameSign = false;
    if (( dividend >= 0) && (divisor >= 0))  {
        sameSign = true;
    } else if (( dividend < 0) && (divisor < 0)) {
        sameSign = true;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    int i;
    int tmp;
    int res =0;
    for (i = 31; i >=0; i--) {
        tmp = (dividend >> i);
        res = (res << 1) + (tmp >= divisor);
        if(tmp >= divisor) {
            //101101 除以10，右移4 与 10 比大小，divisor 左移4位变成 100000，与被除数相减，变成 1101
            dividend -= divisor << i;
        }
    }
    //res 就是结果
    if (flag) {
        //结果+1 或者减1
        if (sameSign) {
            //两个负数，商是正数
            return (res != INT_MAX) ? (res+1):res;
        } else {
            //一个负数，一个正数，结果负数
            return -res-1;
        }
    }
    return sameSign? res: (-res);
}


// @lc code=end

