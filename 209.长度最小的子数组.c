/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (44.37%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    82K
 * Total Submissions: 184.9K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续
 * 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 * 
 */

// @lc code=start


int minSubArrayLen(int s, int* nums, int numsSize){
    int i = 0, j = 0, sum = 0, min = 0;
    while(true){
        if(sum < s){
            if(j == numsSize)
                break;
            sum += nums[j++];
        }else{
            if(min == 0)
                min = j - i;
            min = fmin(min, j - i);
            if(min == 1)
                return min;
            sum -= nums[i++];
        }
    }
    return min;
}


// @lc code=end

