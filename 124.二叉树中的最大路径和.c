/*
 * @lc app=leetcode.cn id=124 lang=c
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (42.97%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    69.1K
 * Total Submissions: 160.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
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


int DfsSum(struct TreeNode* root, int *sum){
    int leftMax = 0;
    int rightMax = 0;
    int tmp;
    if (root == NULL)
        return 0;
    leftMax = DfsSum(root->left, sum);
    rightMax = DfsSum(root->right, sum);
    *sum = fmax(*sum, leftMax + root->val + rightMax);
    tmp = fmax(leftMax, rightMax) + root->val;
    return fmax(0, tmp);
}
int maxPathSum(struct TreeNode* root){
    int sum = INT_MIN;
    DfsSum(root, &sum);
    return sum;
}


// @lc code=end

