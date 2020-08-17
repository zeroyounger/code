/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (66.62%)
 * Likes:    604
 * Dislikes: 0
 * Total Accepted:    57.8K
 * Total Submissions: 86.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：3
 * 输出：
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释：
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 8
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateSubTrees(int s, int e, int* returnSubSize){
    struct TreeNode** subArr = (struct TreeNode**)malloc(2000*sizeof(struct TreeNode*));
    int subArrLen = 0;
    for(int i = s; i <= e; i++){
        int leftSubSize = 0;
        struct TreeNode** leftSubArr = generateSubTrees(s, i-1, &leftSubSize);
        int rightSubSize = 0;
        struct TreeNode** rightSubArr = generateSubTrees(i+1, e, &rightSubSize);
        for(int l = 0; l < leftSubSize; l++){
            for(int r = 0; r < rightSubSize; r++){
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftSubArr[l];
                root->right = rightSubArr[r];
                subArr[subArrLen] = root;
                subArrLen++;
            }
        }
    }
    if(s > e){
        subArr[subArrLen] = NULL;
        subArrLen++;
    }
    *returnSubSize = subArrLen;
    return subArr;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode** ans = (struct TreeNode**)malloc(2000*sizeof(struct TreeNode*));
    if(n < 1){
        *returnSize = 0;
        return NULL;
    }
    int returnSubSize = 0;
    ans = generateSubTrees(1, n, &returnSubSize);
    *returnSize = returnSubSize;
    return ans;
}
// @lc code=end

