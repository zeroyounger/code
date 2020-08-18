/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (56.70%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    80.5K
 * Total Submissions: 141.9K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */

// @lc code=start


int missingNumber(int* nums, int numsSize){
    int res=numsSize;
    for (int i=0; i!= numsSize; ++i){
        res ^= nums[i];
        res ^= i;
    }
    return res;
}


// @lc code=end

