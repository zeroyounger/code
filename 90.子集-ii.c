/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (60.70%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    44.3K
 * Total Submissions: 73K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comfunc(const void *p1,const void *p2){
    return (*(int*)p1)-(*(int*)p2);
}
void dfs(int first,int *path,int depth,int **ret,int *retSize,int *retColSize,int *nums,int numsSize){//result
        ret[*retSize]=(int *)malloc(sizeof(int)*numsSize);
        for(int j=0;j<depth;j++)
            ret[*retSize][j]=path[j];
        retColSize[*retSize]=depth;
        *retSize=*retSize+1;
    for(int i=first;i<numsSize;i++){
        if(i>first&&nums[i]==nums[i-1]) continue;
        path[depth]=nums[i];
        depth++;
        if(depth<=numsSize)  dfs(i+1,path,depth,ret,retSize,retColSize,nums,numsSize);
        depth--;
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),comfunc);
    int *path=(int *)malloc(sizeof(int )*numsSize);
    int retSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*17000);
    int **ret=(int **)malloc(sizeof(int*)*17000);
    if(numsSize>0) dfs(0,path,0,ret,&retSize,*returnColumnSizes,nums,numsSize);
    *returnSize=retSize;
    return ret;
}

// @lc code=end

