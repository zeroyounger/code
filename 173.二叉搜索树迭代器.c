/*
 * @lc app=leetcode.cn id=173 lang=c
 *
 * [173] 二叉搜索树迭代器
 *
 * https://leetcode-cn.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (74.07%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 36.8K
 * Testcase Example:  '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n' +
  '[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
 * 
 * 调用 next() 将返回二叉搜索树中的下一个最小的数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // 返回 3
 * iterator.next();    // 返回 7
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 9
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 15
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 20
 * iterator.hasNext(); // 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
 * 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
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



typedef struct {
    int nums[10000];
    int top;
} BSTIterator;

void ReverseInOrder(struct TreeNode *root, BSTIterator *obj){
    if (root->right != NULL) {
        ReverseInOrder(root->right, obj);
    }
    obj->nums[++obj->top] = root->val;
    if (root->left != NULL) {
        ReverseInOrder(root->left, obj);
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    BSTIterator *obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    if (obj == NULL) {
        return NULL;
    }
    obj->top = -1;
    ReverseInOrder(root, obj);
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    int num;
    num =  obj->nums[obj->top];
    --obj->top;
    return num;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
    if (obj == NULL) {
        return false;
    }
    if (obj->top < 0) {
        return false;
    }
    return true;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
// @lc code=end

