/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (70.92%)
 * Likes:    516
 * Dislikes: 0
 * Total Accepted:    76.6K
 * Total Submissions: 108K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 
 * 
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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


void flatten(struct TreeNode* root){
    if(root == NULL || (root->left == NULL&&root->right==NULL)) return;
    flatten(root->left);
    flatten(root->right);
    if(root->left){
        struct TreeNode *p = root->left;
        while(p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }   
}
// @lc code=end

