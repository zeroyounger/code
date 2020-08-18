/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (66.74%)
 * Likes:    570
 * Dislikes: 0
 * Total Accepted:    100.5K
 * Total Submissions: 150.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 
 * 
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0)
        return 0;
    int i, j, res;
    int *dp = (int*)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    for (i = 0; i < triangleColSize[triangleSize-1]; i++)
        dp[i] = triangle[triangleSize-1][i];
    for (i = triangleSize - 2; i >= 0; i--)
        for (j = 0; j < triangleColSize[i]; j++)
            dp[j] = (dp[j] > dp[j+1]) ? dp[j+1] + triangle[i][j] : dp[j] + triangle[i][j];
    res = dp[0];
    free(dp);
    return res;
}

// @lc code=end

