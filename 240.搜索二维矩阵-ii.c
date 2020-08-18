/*
 * @lc app=leetcode.cn id=240 lang=c
 *
 * [240] 搜索二维矩阵 II
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    73.2K
 * Total Submissions: 175.1K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 * 
 * 
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 
 * 示例:
 * 
 * 现有矩阵 matrix 如下：
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * 给定 target = 5，返回 true。
 * 
 * 给定 target = 20，返回 false。
 * 
 */

// @lc code=start
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target){
    int i= 0 ,j = 0;
    if(matrixRowSize == 0 ||matrixColSize == 0) return false;
    if(target>matrix[matrixRowSize-1][matrixColSize-1] || target<matrix[0][0]) return false;
    while (i<matrixRowSize && j<matrixColSize){
        if(matrix[matrixRowSize-1-i][j]==target) return true;
        if(matrix[matrixRowSize-1-i][j]>target) i++;
        else j++;
    }
    return false;
}
// @lc code=end

