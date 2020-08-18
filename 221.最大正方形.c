/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (42.75%)
 * Likes:    517
 * Dislikes: 0
 * Total Accepted:    67.2K
 * Total Submissions: 157.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */

// @lc code=start


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
	int i, j, max;
	int** dp = (int**)malloc(sizeof(int*) * matrixSize);
	for(i = 0; i < matrixSize; i++)
		dp[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
	max = 0;
	for(i = 0; i < matrixSize; i++)
		for(j = 0; j < matrixColSize[0]; j++)
			if(matrix[i][j] == '1'){
				dp[i][j] = fmin(i > 0 && j > 0 ? dp[i-1][j-1] : 0, fmin(j > 0 ? dp[i][j-1] : 0, i > 0 ? dp[i-1][j] : 0)) + 1;
				max = fmax(max, dp[i][j]);
            }
			else
				dp[i][j] = 0;
	return max * max;
}
// @lc code=end

