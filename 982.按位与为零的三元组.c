/*
 * @lc app=leetcode.cn id=982 lang=c
 *
 * [982] 按位与为零的三元组
 *
 * https://leetcode-cn.com/problems/triples-with-bitwise-and-equal-to-zero/description/
 *
 * algorithms
 * Hard (50.02%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 2.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个整数数组 A，找出索引为 (i, j, k) 的三元组，使得：
 * 
 * 
 * 0 <= i < A.length
 * 0 <= j < A.length
 * 0 <= k < A.length
 * A[i] & A[j] & A[k] == 0，其中 & 表示按位与（AND）操作符。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[2,1,3]
 * 输出：12
 * 解释：我们可以选出如下 i, j, k 三元组：
 * (i=0, j=0, k=1) : 2 & 2 & 1
 * (i=0, j=1, k=0) : 2 & 1 & 2
 * (i=0, j=1, k=1) : 2 & 1 & 1
 * (i=0, j=1, k=2) : 2 & 1 & 3
 * (i=0, j=2, k=1) : 2 & 3 & 1
 * (i=1, j=0, k=0) : 1 & 2 & 2
 * (i=1, j=0, k=1) : 1 & 2 & 1
 * (i=1, j=0, k=2) : 1 & 2 & 3
 * (i=1, j=1, k=0) : 1 & 1 & 2
 * (i=1, j=2, k=0) : 1 & 3 & 2
 * (i=2, j=0, k=1) : 3 & 2 & 1
 * (i=2, j=1, k=0) : 3 & 1 & 2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 1000
 * 0 <= A[i] < 2^16
 * 
 * 
 */

// @lc code=start


int countTriplets(int* A, int ASize){

}


// @lc code=end

