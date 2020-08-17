/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.75%)
 * Likes:    710
 * Dislikes: 0
 * Total Accepted:    120.3K
 * Total Submissions: 154.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int count(int num, int k) {
    int i = 0, count = 0;
    for(i = 0; i < k; i++) {
        if(num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = 1, i = 0, j = 0, k = 0;
    int t = (int)pow(2, numsSize);
    *returnSize = t;
    int** result = (int**)malloc(t * sizeof(int*));
    returnColumnSizes[0] = (int*)malloc(t * sizeof(int));  
    for(i = 0; i < t; i++) {
        returnColumnSizes[0][i] = count(i, numsSize);
        result[i] = (int*)malloc(returnColumnSizes[0][i] * sizeof(int));
        k = i;
        size = 0;
        for(j = 0; j < numsSize; j++) {
            if(k & 1)
                result[i][size++] = nums[j];
            k >>= 1;
        }
    }
    return result;
}

// @lc code=end

