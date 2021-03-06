/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.75%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 77.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        * returnSize = 0;
        return NULL;
    }
    char **set = (char **) malloc(sizeof(char *) * 64);
    for (int i = 0; i < 64; ++i) {
        set[i] = (char *)malloc(sizeof(char) * 64);
    }
    *returnSize = 0;
    dfs_fun(root, set, returnSize, 0);
    ++(*returnSize);
    return set;
}
int dfs_fun(struct TreeNode* root, char **set, int *n, int i)
{
    int tmp;
    if (root->left != NULL && root->right != NULL) {//分支节点
        int tmp1 = *n;
		sprintf(&set[tmp1][i], "%d->", root->val);//防止值为负数
		i = strlen(set[tmp1]);//获得添加后字符串长度

        dfs_fun(root->left, set, n, i);
        ++(*n);//写到下一行字符串
        memcpy(set[*n], set[tmp1], i);
        dfs_fun(root->right, set, n, i);
    }else if (root->left != NULL) {
		sprintf(&set[*n][i], "%d->", root->val);
		i = strlen(set[*n]);		
        dfs_fun(root->left, set, n, i);
    }else if (root->right != NULL) {
		sprintf(&set[*n][i], "%d->", root->val);
		i = strlen(set[*n]);	      
        dfs_fun(root->right, set, n, i);
    }else {//叶子节点
        sprintf(&set[*n][i], "%d", root->val);
    }
    return 0;
}

// @lc code=end

