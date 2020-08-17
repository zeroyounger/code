/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (42.30%)
 * Likes:    524
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 184.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start


int direction[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool dfs(char **board, int boardSize, int boardColSize, int row, int col, int comb, char *word, int word_len) {
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize)
        return false;
    if (board[row][col] != word[comb])
        return false;
    if ((++comb) == word_len)
        return true;
    board[row][col] = '.';
    for (int i = 0; i < 4; i++)
        if (dfs(board, boardSize, boardColSize, row + direction[i][0], col + direction[i][1], comb, word, word_len))
            return true;
    board[row][col] = word[comb - 1];
    return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < (*boardColSize); j++)
            if (dfs(board, boardSize, *boardColSize, i, j, 0, word, strlen(word)))
                return true;
    return false;
}


// @lc code=end

