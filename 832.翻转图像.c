/*
 * @lc app=leetcode.cn id=832 lang=c
 *
 * [832] 翻转图像
 *
 * https://leetcode-cn.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (75.15%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 46.2K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * 给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
 * 
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
 * 
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [[1,1,0],[1,0,1],[0,0,0]]
 * 输出: [[1,0,0],[0,1,0],[1,1,1]]
 * 解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 * ⁠    然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * 输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 * ⁠    然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){

}


// @lc code=end

