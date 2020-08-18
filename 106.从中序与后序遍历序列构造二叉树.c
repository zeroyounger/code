/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (69.30%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    47.4K
 * Total Submissions: 68.4K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize == 0)
           return NULL;
    int i = 0;
    while (inorder[inorderSize - 1 - i] != postorder[postorderSize - 1])
        ++i;
    assert(i >= 0);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    root->left = buildTree(inorder, inorderSize - i - 1, postorder, inorderSize - i - 1);
    root->right = buildTree(inorder + inorderSize - i, i, postorder + postorderSize - i - 1, i);
    return root;
}


// @lc code=end

