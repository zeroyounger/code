/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.16%)
 * Likes:    554
 * Dislikes: 0
 * Total Accepted:    122.1K
 * Total Submissions: 304.1K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int edgeOfLeft(int *nums, int numsSize, int target){
    int low = 0, high = numsSize, mid;
    while (low < high){
        mid = (low + high) / 2;
        if (nums[mid] == target)
            high = mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(2 * sizeof(int));
    res[0] = res[1] = -1;
    int index = edgeOfLeft(nums, numsSize, target);
    if (index > numsSize - 1)
        return res;
    else if (nums[index] != target)
        return res;
    else {
        res[0] = res[1] = index;
        if (index != numsSize - 1){
            while (index < numsSize){
                if (nums[index] == target)
                    res[1] = index;
                index++;
            }
        }
    }
    return res;
}
// @lc code=end

