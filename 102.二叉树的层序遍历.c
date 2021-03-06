/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.17%)
 * Likes:    600
 * Dislikes: 0
 * Total Accepted:    179.1K
 * Total Submissions: 283.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void bfs(struct TreeNode* root, int* returnSize, int* returnColumnSizes, int **retVal){
    struct TreeNode* queue[10000] = {0};
    int front, back;
    struct TreeNode* cur;
    front = back = 0;
    queue[back++] = root;
    while (front < back) {
        int cnt = back - front;
        returnColumnSizes[*returnSize] = cnt;
        retVal[*returnSize] = malloc(sizeof(int) * 10240);
        for (int i = 0; i < cnt; i++) {
            cur = queue[front++];
            retVal[*returnSize][i] = cur->val;
            if (cur->left)
                queue[back++] = cur->left;
            if (cur->right)
                queue[back++] = cur->right;
        }
        (*returnSize)++;
    }
    return;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **retVal = (int *)malloc(sizeof(int) * 10240);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10240);
    *returnSize = 0;
    if (root == NULL)
        return NULL;
    bfs(root, returnSize, *returnColumnSizes, retVal);
    return retVal;
}


// @lc code=end

