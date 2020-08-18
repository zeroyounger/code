/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (64.20%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    61.6K
 * Total Submissions: 96K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
#define MAX 1000
int* rightSideView(struct TreeNode* root, int* returnSize){
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int) * MAX);
    int arrIndex = 0;
    struct TreeNode *queue[MAX];
    int head = 0;
    int tail = 0;
    int size = 0;
    tail = (tail + 1) % MAX;
    queue[tail] = root;
    size++;
    while (head != tail) {
        int tmp = size;
        ans[arrIndex] = queue[tail]->val;
        arrIndex++;
        while (tmp > 0) {
            head = (head + 1) % MAX;
            struct TreeNode *p = queue[head];
            size--;
            if (p->left != NULL) {
                tail = (tail + 1) % MAX;
                queue[tail] = p->left;
                size++;
            }
            if (p->right != NULL) {
                tail = (tail + 1) % MAX;
                queue[tail] = p->right;
                size++;
            }
            tmp--;
        }
    }
    *returnSize = arrIndex;
    return ans;
}


// @lc code=end

