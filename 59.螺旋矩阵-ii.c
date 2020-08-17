/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (77.97%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    43.2K
 * Total Submissions: 55.4K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **g = (int **)malloc(sizeof(int *) * n);
    returnColumnSizes[0] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        g[i] = (int *)malloc(sizeof(int) * n);
        returnColumnSizes[0][i] = n;
    }
    int up = 0;
    int left = 0;
    int right = n - 1;
    int down = n -1;
    int cnt = 1;
    while (1) {
        for(int i = left; i <= right; i++)
            g[up][i] = cnt++;
        if(++up > down)
            break;
        for(int i = up; i <= down; i++)
            g[i][right] = cnt++;
        if(--right < left)
            break;
        for (int i = right; i >=left; i--)
            g[down][i] = cnt++;
        if(--down < up)
            break;
        for (int i = down; i >= up; i--)
            g[i][left] = cnt++;
        if(++left >right)
            break;
    }
    *returnSize = n;
    return g;
}


// @lc code=end

