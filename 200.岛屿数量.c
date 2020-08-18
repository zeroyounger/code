/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (50.07%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    143.6K
 * Total Submissions: 286.9K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ['1','1','1','1','0'],
 * ['1','1','0','1','0'],
 * ['1','1','0','0','0'],
 * ['0','0','0','0','0']
 * ]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ['1','1','0','0','0'],
 * ['1','1','0','0','0'],
 * ['0','0','1','0','0'],
 * ['0','0','0','1','1']
 * ]
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */

// @lc code=start


void dfs(char **g, int m, int n, int i, int j){
    g[i][j] = '2';
    if (i > 0 && g[i - 1][j] == '1')
        dfs(g, m, n, i - 1, j);
    if (j > 0 && g[i][j - 1] == '1')
        dfs(g, m, n, i, j - 1);
    if (i < m - 1 && g[i + 1][j] == '1')
        dfs(g, m, n, i + 1, j);
    if (j < n - 1 && g[i][j + 1] == '1')
        dfs(g, m, n, i, j + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (!grid || !gridSize || !gridColSize || !(*gridColSize))
        return 0;
    int colSize = *gridColSize;
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, gridSize, colSize, i, j);
                count += 1;
            }
        }
    }
    return count;
}
// @lc code=end

