/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (62.50%)
 * Likes:    334
 * Dislikes: 0
 * Total Accepted:    75.9K
 * Total Submissions: 121.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int g_target = 0;
int g_candidatesSize = 0;
int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void calcSum(int i, int candidates[], int sum, int cnt, int temp[], int** retCand, int* returnSize, int** returnColumnSizes){
    if (g_target == sum){
        retCand[*returnSize] = (int *)malloc(sizeof(int)*cnt);
        (*returnColumnSizes)[*returnSize] = cnt;
        memcpy(retCand[*returnSize], temp, sizeof(int)*cnt);
        (*returnSize)++;
        return;
    }
    while ((i < g_candidatesSize) && (sum + candidates[i] <= g_target)) {
        temp[cnt++] = candidates[i];
        calcSum(i+1, candidates, sum + candidates[i], cnt, temp, retCand, returnSize, returnColumnSizes);
        i++;
        cnt--;
        while ((i < g_candidatesSize) && (candidates[i] == candidates[i-1])) {
            i++;
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    if ((candidates == NULL) || (candidatesSize <= 0))
        return 0;
    int temp[candidatesSize], cnt;
    int **retCand = (int **)malloc(sizeof(int *) * 2 * candidatesSize);
    (*returnSize) = 0;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * 2 * candidatesSize);
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    cnt = 0;
    g_target = target;
    g_candidatesSize = candidatesSize;
    calcSum(0, candidates, 0, cnt, temp, retCand, returnSize, returnColumnSizes);
    return retCand;
}


// @lc code=end

