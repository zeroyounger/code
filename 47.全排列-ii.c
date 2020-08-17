/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (59.61%)
 * Likes:    374
 * Dislikes: 0
 * Total Accepted:    80.3K
 * Total Submissions: 134.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
void dfs(int depth,int *nums,int numsSize,int **ret,int *retSize,int *mark,int *path){
    for(int i=0;i<numsSize;i++){
        if(mark[i]==0) continue;
        if(i>0&&nums[i]==nums[i-1]&&mark[i-1]==1) continue;
        mark[i]=0;
        path[depth]=nums[i];
        depth++;
        //result
        if(depth==numsSize){
            ret[*retSize]=(int *)malloc(sizeof(int)*numsSize);
            for(int i=0;i<numsSize;i++)
                ret[*retSize][i]=path[i];
            *retSize=*retSize+1;
        }
        if(depth<numsSize) dfs(depth,nums,numsSize,ret,retSize,mark,path);
        depth--;
        mark[i]=1;
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),comfunc);
    int **ret=(int **)malloc(sizeof(int*)*17000);
    int retSize=0;
    int *mark=(int *)malloc(sizeof(int)*numsSize);
    int *path=(int*)malloc(sizeof(int)*numsSize);
    dfs(0,nums,numsSize,ret,&retSize,mark,path);
    *returnSize=retSize;
    *returnColumnSizes=(int *)malloc(sizeof(int)*retSize);
    for(int i=0;i<retSize;i++)
        (*returnColumnSizes)[i]=numsSize;
    return ret;
}


// @lc code=end

