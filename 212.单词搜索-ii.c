/*
 * @lc app=leetcode.cn id=212 lang=c
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (42.28%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 45.7K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 示例:
 * 
 * 输入: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * 输出: ["eat","oath"]
 * 
 * 说明:
 * 你可以假设所有输入都由小写字母 a-z 组成。
 * 
 * 提示:
 * 
 * 
 * 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 * 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
 * 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct tagNode Node;
struct tagNode {
    Node *child[26];
    bool end;
    char *word;
};
Node *TrieInit(void){
    Node *root = calloc(1, sizeof(Node));
    return root;
}
void TrieInsert(Node *root, char *word){
    char *c;
    Node *parent = root;
    for (c = word; *c != 0; c++) {
        if (parent->child[*c-'a'] == NULL) {
            parent->child[*c-'a'] = calloc(1, sizeof(Node));
        }
        parent = parent->child[*c-'a'];
    }
    parent->end = true;
    parent->word = strdup(word);
    return;
}
void Dfs(Node *node, char **board, int maxRow, int maxCol, int row, int col, char **ret, int *retSize){
    int idx;
    char ori;
    Node *child = NULL;
    if (row >= maxRow || row < 0 || col < 0 || col >= maxCol || board[row][col] == '#') {
        return;
    }
    idx = board[row][col] - 'a';
    child = node->child[idx];
    if (child == NULL) {
        return;
    }
    if (child->end) {
        child->end = false;
        ret[*retSize] = strdup(child->word);
        (*retSize)++;
    }
    ori = board[row][col];
    board[row][col] = '#';
    Dfs(child, board, maxRow, maxCol, row + 1, col, ret, retSize);
    Dfs(child, board, maxRow, maxCol, row - 1, col, ret, retSize);
    Dfs(child, board, maxRow, maxCol, row, col + 1, ret, retSize);
    Dfs(child, board, maxRow, maxCol, row, col - 1, ret, retSize);
    board[row][col] = ori;
    return;
}
void TrieSearch(Node *root, char **board, int row, int col, char **ret, int *retSize){
    int i, j;
    Node *node = root;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            Dfs(node, board, row, col, i, j, ret, retSize);
        }
    }
    return;
}
char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    int i;
    Node *Trie = NULL;
    char **ret = NULL;
    *returnSize = 0;
    if (wordsSize == 0 || boardSize == 0 || *boardColSize == 0) {
        return NULL;
    }
    Trie = TrieInit();
    for (i = 0; i < wordsSize; i++) {
        TrieInsert(Trie, words[i]);
    }
    ret = calloc(wordsSize, sizeof(char*));
    TrieSearch(Trie, board, boardSize, *boardColSize, ret, returnSize);
    return ret;
}


// @lc code=end

