/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.21%)
 * Likes:    731
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 207.2K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 * 
 */

// @lc code=start


int firstMissingPositive(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        int j = nums[i];
        nums[i] = 0;
        while (j <= numsSize && j > 0 && nums[j - 1] != j) {
            int j_new = nums[j - 1];
            nums[j - 1] = j;
            j = j_new;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        if (nums[j - 1] != j)
            return j;
    }
    return numsSize + 1;
}
// @lc code=end

