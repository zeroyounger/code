/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (73.80%)
 * Likes:    551
 * Dislikes: 0
 * Total Accepted:    106.5K
 * Total Submissions: 144.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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


struct TreeNode* buildTree(int* nums, int l, int r){
    if (l>r) return NULL;
    int mid = l+(r-l)/2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=nums[mid];
    root->left=buildTree(nums,l,mid-1);
    root->right=buildTree(nums,mid+1,r);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return buildTree(nums, 0, numsSize - 1);
}

// @lc code=end

