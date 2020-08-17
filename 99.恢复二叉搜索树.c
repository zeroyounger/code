/*
 * @lc app=leetcode.cn id=99 lang=c
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (62.11%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 59.6K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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


typedef struct TreeNode TreeNode;
void recoverTree(struct TreeNode* cur){
    TreeNode* stack[1000];
    int idx = 0;
    TreeNode*pre = NULL;
    TreeNode* errorNode1 = NULL, *errorNode2 = NULL;
    while (cur != NULL || idx != 0) {
        while (cur != NULL) {
            stack[idx++] = cur;
            cur = cur->left;
        }
        cur = stack[--idx];
        if (pre != NULL && cur->val < pre->val) {
            if (errorNode1 == NULL) errorNode1 = pre;
            errorNode2 = cur;
        }
        pre = cur;
        cur = cur->right;
    }
    int v = errorNode1->val;
    errorNode1->val = errorNode2->val;
    errorNode2->val = v;
}
// @lc code=end

