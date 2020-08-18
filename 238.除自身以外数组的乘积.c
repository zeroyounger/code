/*
 * @lc app=leetcode.cn id=238 lang=c
 *
 * [238] 除自身以外数组的乘积
 *
 * https://leetcode-cn.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (70.66%)
 * Likes:    557
 * Dislikes: 0
 * Total Accepted:    74.6K
 * Total Submissions: 105.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i]
 * 之外其余各元素的乘积。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 
 * 
 * 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
 * 
 * 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 进阶：
 * 你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize == 0) {
        returnSize = 0;
        return NULL;
    }
    int arr1[numsSize];
    int arr2[numsSize];
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            arr1[i] = nums[i];
            continue;
        }
        arr1[i] = arr1[i - 1] * nums[i];
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        if (i == numsSize - 1) {
            arr2[i] = nums[i];
            continue;
        }
        arr2[i] = arr2[i + 1] * nums[i];
    }
    int *out = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (i == 0)
            out[i] = arr2[i + 1];
        else if (i == numsSize - 1)
            out[i] = arr1[i - 1];
        else
            out[i] = arr1[i - 1] * arr2[i + 1];
    }
    *returnSize = numsSize;
    return out;
}


// @lc code=end

