/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (42.18%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    67.6K
 * Total Submissions: 160.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start


void Dfs(char** board, int boardSize, int colSize, int x, int y){
    if ((x < 0 || x > boardSize-1 || y < 0 || y > colSize - 1) || board[x][y] != 'O')
        return;
    board[x][y] = 'B';
    Dfs(board, boardSize, colSize, x + 1, y);
    Dfs(board, boardSize, colSize, x, y + 1);
    Dfs(board, boardSize, colSize, x - 1, y);
    Dfs(board, boardSize, colSize, x, y -1);
    return;
}
void solve(char** board, int boardSize, int* boardColSize) {
    if (board == NULL || boardSize < 1 || boardColSize == NULL) return;
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardColSize[i]; j++)
            if ((i == 0 || i == boardSize - 1 || j == 0 || j == boardColSize[i] - 1) && board[i][j] == 'O')
                Dfs(board, boardSize, boardColSize[i], i, j);
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else  if (board[i][j] == 'B')
                board[i][j] = 'O';
        }
    }
    return;
}
// @lc code=end

