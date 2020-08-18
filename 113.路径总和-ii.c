/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    67K
 * Total Submissions: 110.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
#define MAX 1000
int *all[MAX];
int allsize[MAX];
int cnt;
void traverse (struct TreeNode *root, int *before, int size, int sum){
    int i;
    int *copyleft;
    int *copyright;
    int *copy;
    if (root == NULL)
        return;
    before[size++] = root->val;
    if (root->left == NULL && root->right == NULL && root->val == sum) {
        copy = malloc(sizeof(int) * (size));
        memcpy(copy, before, sizeof(int) * size);
        allsize[cnt] = size;
        all[cnt++] = copy;
        return;
    }
    if (root->left != NULL)
        traverse(root->left, before, size, sum - root->val);
    if (root->right != NULL)
        traverse(root->right, before, size, sum - root->val);
    return;
}
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int *before = malloc(sizeof(int) * MAX);
    cnt = 0;
    traverse(root, before, 0, sum);
    *returnColumnSizes = allsize;
    *returnSize = cnt;
    free(before);
    return all;
}


// @lc code=end

