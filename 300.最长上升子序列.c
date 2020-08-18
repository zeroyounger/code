/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (45.10%)
 * Likes:    907
 * Dislikes: 0
 * Total Accepted:    131.2K
 * Total Submissions: 291K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start


int lengthOfLIS(int* nums, int numsSize){
    int max = 0;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(nums[i] > nums[j])
                dp[i] = fmax(dp[i], dp[j] + 1);
        max = fmax(max, dp[i]);
    }
    return max;
}


// @lc code=end

