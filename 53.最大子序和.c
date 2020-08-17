/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (52.08%)
 * Likes:    2306
 * Dislikes: 0
 * Total Accepted:    303.6K
 * Total Submissions: 583.1K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4]
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start


int maxSubArray(int* nums, int numsSize){
    int ans=nums[0];
    int sum=0;
    for(int i=0;i!=numsSize;i++){
        if(sum>0) sum+=nums[i];
        else sum=nums[i];
        ans=fmax(ans,sum);
    }
    return ans;
}

// @lc code=end

