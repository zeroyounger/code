/*
 * @lc app=leetcode.cn id=63 lang=c
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (36.52%)
 * Likes:    394
 * Dislikes: 0
 * Total Accepted:    94.9K
 * Total Submissions: 259.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long dp[100][100] = {0};
    int i, j;
    for (i = 0; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 1) break; //初始化第1列的值，如果存在不可达，则剩余均不可达。
        dp[i][0] = 1;
    }
    for (j = 0; j < * obstacleGridColSize; j++) {
        if (obstacleGrid[0][j] == 1) break; //初始化第1行的值，如果存在不可达，则剩余均不可达。
        dp[0][j] = 1;
    }
    for (i = 1; i < obstacleGridSize; i++)
        for (j = 1; j < * obstacleGridColSize; j++)
            if (obstacleGrid[i][j] != 1)   // 如果节点不可达，则不需要计算，默认值0，到此节点不可达，继续计算下一个节点，遍历到最终节点为止。
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[obstacleGridSize-1][* obstacleGridColSize-1];    // dp中已经记录好每个节点最多路径，直接返回数组节点值即可。
}
// @lc code=end

