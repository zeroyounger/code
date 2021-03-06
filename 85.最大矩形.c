/*
 * @lc app=leetcode.cn id=85 lang=c
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (47.54%)
 * Likes:    548
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 80.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start


int maximalRectangle(char ** matrix, int matrixSize, int * matrixColSize){
    int maxSize = 0;
    if (matrixSize > 0) {
        int deep[matrixColSize[0]];
        for (int i = 0; i < matrixColSize[0]; i++)
            deep[i] = 0;
        for (int x = 0; x < matrixSize; x++) {
            for (int y = 0; y < matrixColSize[0]; y++) {
                if (matrix[x][y] == '0') {
                    deep[y] = 0;
                } else {
                    deep[y]++;
                    int now = y;
                    int high = deep[y];
                    while (now >= 0 && deep[now] > 0) {
                        if (deep[now] < high)
                            high = deep[now];
                        maxSize = maxSize > (high * (y - now + 1))? maxSize: (high * (y - now + 1));
                        now--;
                    }
                }
            }
        }
    }
    return maxSize;
}


// @lc code=end

