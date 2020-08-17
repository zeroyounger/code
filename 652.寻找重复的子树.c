/*
 * @lc app=leetcode.cn id=652 lang=c
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode-cn.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 18.9K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 * 
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 * 
 * 示例 1：
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * 下面是两个重复的子树：
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * 和
 * 
 * ⁠   4
 * 
 * 
 * 因此，你需要以列表的形式返回上述重复子树的根结点。
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize){

}
// @lc code=end

