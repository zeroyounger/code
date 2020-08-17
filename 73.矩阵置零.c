/*
 * @lc app=leetcode.cn id=73 lang=c
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (55.79%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    50.3K
 * Total Submissions: 90.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */

// @lc code=start


void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int** temp;
    temp = malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
        *(temp + i) = malloc(*(matrixColSize + i) * sizeof(int));
    int row = matrixSize;
    int col = matrixColSize[0];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            temp[i][j] = matrix[i][j];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (temp[i][j] == 0) {
                int k;
                for (k = 0; k < row; k++)
                    matrix[k][j] = 0;
                for (k = 0; k < col; k++)
                    matrix[i][k] = 0;
            }
        }
    } 
}
// @lc code=end

