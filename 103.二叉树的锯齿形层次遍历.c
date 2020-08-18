/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.81%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    65K
 * Total Submissions: 118.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    struct TreeNode* queue[10000];
    int head = 0, tail = 0;
    struct TreeNode* p;
    int **ans;
    ans = (int **)malloc(sizeof(int *) * 100);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if (!root) return ans;
    queue[tail++] = root;
    int flag = 1;
    int count = 0;
    while (tail > head) {
        (*returnColumnSizes)[*returnSize] = tail - head;
        ans[*returnSize] = (int *)malloc(sizeof(int) * (tail - head));
        for (int i = 0; i < (*returnColumnSizes)[*returnSize]; i++) {
            p = queue[head++];
            if (flag) ans[*returnSize][i] = p -> val;
            else ans[*returnSize][(*returnColumnSizes)[*returnSize] - i - 1] = p -> val;
            if (p -> left) queue[tail++] = p -> left;
            if (p -> right) queue[tail++] = p -> right;
        }
        *returnSize += 1;
        flag = 1 - flag;
    }
    return ans;
}


// @lc code=end

