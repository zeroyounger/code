/*
 * @lc app=leetcode.cn id=109 lang=c
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (73.39%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    37.6K
 * Total Submissions: 51.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* fun(struct ListNode *left,struct ListNode *right){
    if(left==right)return NULL;
    struct ListNode *slow=left,*fast=left;
    while(fast!=right&&fast->next!=right){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val=slow->val;
    root->left=fun(left,slow);
    root->right=fun(slow->next,right);
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    return fun(head,NULL);
}
// @lc code=end

