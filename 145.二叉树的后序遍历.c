/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (72.18%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    108.5K
 * Total Submissions: 150.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
#define MAX 1000
void postOrder(struct TreeNode* root, int* array, int* returnSize){
    if(root){
        postOrder(root->left, array, returnSize);
        postOrder(root->right, array, returnSize);
		array[(*returnSize)++] = root->val;
    }
	array[*returnSize] = '\0';
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	int *array = (int*)malloc(sizeof(int) * MAX);
	postOrder(root, array, returnSize);
	return array;
}




// @lc code=end

