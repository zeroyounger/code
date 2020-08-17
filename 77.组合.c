/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (74.43%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    68.5K
 * Total Submissions: 92.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void fun(int n, int k, int *path,int**result,int *returnSize,int **returnColumnSizes,int K){
    if(k==0){
        result[*returnSize] = (int*)malloc(sizeof(int)*K);
        for(int i=0;i<K;++i)
            result[*returnSize][i] = path[i];
        ++(*returnSize);
        return;
    }
    for(int j=n;j>=k;--j){
        path[k-1] = j;
        fun(j-1,k-1,path,result,returnSize,returnColumnSizes,K);
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int **result = (int**)malloc(sizeof(int*)*5000);    //假设不超过1024行
    int *path = (int*)malloc(sizeof(int)*k);     //记录每一次的路径
    *returnColumnSizes = (int*)malloc(sizeof(int)*5000);
    *returnSize = 0;
    if(n==0||k==0)  return result;
    fun(n,k,path,result,returnSize,returnColumnSizes,k);
    for(int i=0;i<(*returnSize);++i)
        (*returnColumnSizes)[i] = k;
    return result;
}
// @lc code=end

