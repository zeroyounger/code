/*
 * @lc app=leetcode.cn id=229 lang=c
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (43.51%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 44.4K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: [3]
 * 
 * 示例 2:
 * 
 * 输入: [1,1,1,3,3,2,2,2]
 * 输出: [1,2]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int*)a > *(int*)b;
}
int* majorityElement(int* nums, int numsSize, int* returnSize){
if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int *results = (int *)malloc(numsSize * sizeof(int));
    int i, k, tmp, tmpCount;
    k = 0;
    tmp = nums[0];
    int count = numsSize / 3;
    for (i = 0; i < numsSize;) {
        tmpCount = 0;
        while (i < numsSize && nums[i] == tmp) {
            tmpCount++;
            i++;
        }
        if (tmpCount > count) {
            results[k++] = tmp;
        }
        if (i < numsSize)
            tmp = nums[i];
    }
    *returnSize = k;
    return results;
}

// @lc code=end

