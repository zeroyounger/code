/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (62.38%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    37.6K
 * Total Submissions: 60.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start


bool fun(char **board, int row,int col,int (*row_group)[9], int (*col_group)[9], int (*grid_group)[9]){
    bool is = false;
    if (board[row][col] == '.') {
        for (int k = 0; k < 9; ++k){
            if (!row_group[row][k] && !col_group[col][k] && !grid_group[3 * (row / 3) + col / 3][k]){
                row_group[row][k]=1;
                col_group[col][k]=1;
                grid_group[3 * (row / 3) + col / 3][k]=1;
                board[row][col]=k+49;
                int i= row,j=col;
                if(row<9) {col++;}
                if(col==9 && row==8) {return true;}
                if(col==9 && row<9) {col=0;row++;}
                is = fun(board,row,col,row_group,col_group,grid_group);
                if(is){
                    return true;}
                else{
                    row=i;col=j;
                    row_group[row][k]=0;
                    col_group[col][k]=0;
                    grid_group[3 * (row / 3) + col / 3][k]=0;
                    board[row][col]='.';
                }
            }
        }
    }else{
        if(row<9) {col++;}
        if(col==9 && row==8) {return true;}
        if(col==9 && row<9) {col=0;row++;}
        is = fun(board,row,col,row_group,col_group,grid_group);
        if(is){return true;}else{ return false;}
    }
    return false;
}
void solveSudoku(char **board, int boardRowSize, int *boardColSizes){
    int col[9][9] = {0}; int (*cp) [9]=col;
    int row[9][9] = {0}; int (*rp) [9]=row;
    int grid[9][9] = {0}; int (*gp) [9] =grid;
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            int n = board[i][j] - 49;
            col[i][n] = 1;
            row[j][n] = 1;
            grid[3 * (i / 3) + j / 3][n] = 1;
        }
    }
    fun(board,0,0,cp,rp,gp);
}
// @lc code=end

