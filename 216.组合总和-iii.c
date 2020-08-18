/*
 * @lc app=leetcode.cn id=216 lang=c
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.68%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    27.4K
 * Total Submissions: 38.2K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NUM 500
int g_visited[9];
void dfs(int k, int n, int* returnSize, int** returnColumnSizes, int *temp, int index, int start, int **res){
    if (n == 0 && index == k) {
        res[*returnSize] = (int*)malloc(sizeof(int) * index);
        memcpy(res[*returnSize], temp, sizeof(int) * index);
        (*returnColumnSizes)[*returnSize] = index;
        (*returnSize)++;
        return;
    }
    for (int i = start; i <= 9; i++) {
        if (i <= n) {
            temp[index] = i;
            dfs(k, n - i, returnSize, returnColumnSizes, temp, index + 1, i + 1, res);
        }
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int **res = (int**)malloc(sizeof(int*) * MAX_NUM);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * MAX_NUM);
    int sum = 0;
    for (int i = 9; i >= 1; i--)
        sum += i;
    if (n > sum)
        return res;
    memset(g_visited, 0, sizeof(int) * 9);
    int *temp = (int*)malloc(sizeof(int) * 9);
    dfs(k, n, returnSize, returnColumnSizes, temp, 0, 1, res);
    return res;
}

// @lc code=end

