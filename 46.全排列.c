/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.67%)
 * Likes:    843
 * Dislikes: 0
 * Total Accepted:    172.5K
 * Total Submissions: 225K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int *nums,int numsSize,int *mark,int *path,int index,int **result,int *reIndex){
    for(int i=0;i<numsSize;i++){
        if(mark[i]==0) continue;
        mark[i]=0;
        path[index]=nums[i];
        index=index+1;
        if(index==numsSize){
            result[*reIndex]=(int *)malloc(sizeof(int)*numsSize);
            for(int j=0;j<numsSize;j++)
                result[*reIndex][j]=path[j];
            *reIndex=*reIndex+1;
        }
        dfs(nums,numsSize,mark,path,index,result,reIndex);
        mark[i]=1;
        index=index-1;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int mark[numsSize];
    for(int i=0;i<numsSize;i++)
        mark[i]=1;
    int path[numsSize];
    int index=0;
    int **result=(int **)malloc(sizeof(int *)*17000);
    int reIndex=0;
    dfs(nums,numsSize,mark,path,index,result,&reIndex);
    *returnSize=reIndex;
    *returnColumnSizes=(int *)malloc(sizeof(int)*17000);
    for(int i=0;i<reIndex;i++)
        (*returnColumnSizes)[i]=numsSize;
    return result;
}


// @lc code=end

