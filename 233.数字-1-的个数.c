/*
 * @lc app=leetcode.cn id=233 lang=c
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (36.98%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 26.7K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */

// @lc code=start


int countDigitOne(int n){
    long num=n,i=1,s=0;
    while(num){ 
        if(num%10==0)
            s=s+(num/10)*i;
        if(num%10==1) 
            s=s+(num/10)*i+(n%i)+1;
        if(num%10>1) 
            s=s+ceil(num/10.0)*i;
        num=num/10;
        i=i*10;
    }    
    return s;
}


// @lc code=end

