/*
 * @lc app=leetcode.cn id=307 lang=c
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (56.42%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    12.9K
 * Total Submissions: 22.8K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。
 * 
 * 示例:
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 说明:
 * 
 * 
 * 数组仅可以在 update 函数下进行修改。
 * 你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。
 * 
 * 
 */

// @lc code=start



typedef struct {

} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {

}

void numArrayUpdate(NumArray* obj, int i, int val) {

}

int numArraySumRange(NumArray* obj, int i, int j) {

}

void numArrayFree(NumArray* obj) {

}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, i, val);
 
 * int param_2 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
// @lc code=end

