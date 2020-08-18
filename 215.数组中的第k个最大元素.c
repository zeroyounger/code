/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.40%)
 * Likes:    663
 * Dislikes: 0
 * Total Accepted:    187.1K
 * Total Submissions: 290.5K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start


int findKthLargest(int *nums, int numsSize, int k){
    int bucket[20001] = { 0 };
    for (int i = 0; i < numsSize; i++)
        bucket[nums[i] + 10000]++;
    int count= 0, ret = 0;
    for (int j = 20000; j > 0; j--) {
        count += bucket[j];
        if (count >= k) {
            ret = j - 10000;
            break;
        }
    }
    return ret;
}

// @lc code=end

