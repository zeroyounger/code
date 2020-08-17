/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.48%)
 * Likes:    627
 * Dislikes: 0
 * Total Accepted:    135.2K
 * Total Submissions: 200.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int sum[gridSize+1][(*gridColSize)+1];
    memset(sum,0,gridSize*(*gridColSize));
    if(gridSize == 0 || *gridColSize == 0 )
        return 0;
    else if( *gridColSize == 1 && gridSize == 1)
        return grid[0][0];
    else{   
        sum[0][0] = grid[0][0];
        for( i = 1 ; i < *gridColSize ; i++)
            sum[0][i]= grid[0][i] +sum[0][i-1];
        for( i = 1 ; i < gridSize ; i++)
            sum[i][0] = grid[i][0] + sum[i-1][0];
        for(i = 1 ; i<gridSize;i++)
            for(int j = 1;j<(*gridColSize);j++)
                sum[i][j] = fmin(sum[i][j-1]+grid[i][j],sum[i-1][j]+grid[i][j]);
    }
    return sum[gridSize-1][*gridColSize-1];
}


// @lc code=end

