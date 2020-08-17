/*
 * @lc app=leetcode.cn id=1314 lang=c
 *
 * [1314] 矩阵区域和
 *
 * https://leetcode-cn.com/problems/matrix-block-sum/description/
 *
 * algorithms
 * Medium (71.38%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 5.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
 *
 * 给你一个 m * n 的矩阵 mat 和一个整数 K ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
 * mat[r][c] 的和： 
 * 
 * 
 * i - K <= r <= i + K, j - K <= c <= j + K 
 * (r, c) 在矩阵内。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
 * 输出：[[12,21,16],[27,45,33],[24,39,28]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
 * 输出：[[45,45,45],[45,45,45],[45,45,45]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n, K <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes){

}


// @lc code=end

